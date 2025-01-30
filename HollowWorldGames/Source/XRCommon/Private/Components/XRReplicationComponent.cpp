// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/XRReplicationComponent.h"

#include "MotionControllerComponent.h"
#include "UtilityStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/XRHandProxyComponent.h"
#include "Components/XRHeadProxyComponent.h"
#include "Math/UnitConversion.h"
#include "Variables/FloatVariableAsset.h"


FXRReplicatedPosition::FXRReplicatedPosition(const FVector& NewHeadPosition, const FRotator& NewHeadRotation,
	const FVector& NewLeftHandPosition, const FRotator& NewLeftHandRotation, const FVector& NewRightHandPosition,
	const FRotator& NewRightHandRotation, int NewSequence)
{
	HeadPosition = NewHeadPosition;
	HeadRotation = NewHeadRotation;
	LeftPosition = NewLeftHandPosition;
	LeftRotation = NewLeftHandRotation;
	RightPosition = NewRightHandPosition;
	RightRotation = NewRightHandRotation;
	Sequence = NewSequence;
}

// Sets default values for this component's properties
UXRReplicationComponent::UXRReplicationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UXRReplicationComponent::AddReplicatedPosition(const FVector& HeadPosition, const FRotator& HeadRotation,
	const FVector& LeftHandPosition, const FRotator& LeftHandRotation, const FVector& RightHandPosition, const FRotator& RightHandRotation,
	const int& Sequence)
{
	if (ReplicatedPositions.Num() == 0)
	{
		if (PreviousReplicatedPosition.Sequence == 0)
		{
			PreviousReplicatedPosition = FXRReplicatedPosition(HeadPosition, HeadRotation,
				LeftHandPosition, LeftHandRotation,
				RightHandPosition, RightHandRotation, Sequence);
		}
		
	}
	else
	{
		if (ReplicatedPositions[0].Sequence < Sequence)
		{
			ReplicatedPositions.Add(FXRReplicatedPosition(HeadPosition, HeadRotation,
				LeftHandPosition, LeftHandRotation,
				RightHandPosition, RightHandRotation, Sequence));
		}
		else if (ReplicatedPositions[0].Sequence == Sequence)
		{
			ReplicatedPositions[0] = FXRReplicatedPosition(HeadPosition, HeadRotation,
				LeftHandPosition, LeftHandRotation,
				RightHandPosition, RightHandRotation, Sequence);
		}
	}
}

// Called when the game starts
void UXRReplicationComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		TArray<UXRHandProxyComponent*> HandProxies;
		GetOwner()->GetComponents(HandProxies);
		HeadProxyComponent = GetOwner()->GetComponentByClass<UXRHeadProxyComponent>();
		HeadComponent = GetOwner()->GetComponentByClass<UCameraComponent>();
		TArray<UMotionControllerComponent*> MotionControllers;
		GetOwner()->GetComponents(MotionControllers);

		for (auto HandProxy : HandProxies)
		{
			switch (HandProxy->GetHand())
			{
			case EControllerHand::Left :
				{
					LeftProxyComponent = HandProxy;
					break;
				}
			case EControllerHand::Right :
				{
					RightProxyComponent = HandProxy;
					break;
				}
			default :
				{
					break;
				}
			}
		}

		for (auto HandComponent : MotionControllers)
		{
			switch (HandComponent->GetTrackingSource())
			{
			case EControllerHand::Left :
				{
					LeftComponent = HandComponent;
					break;
				}
			case EControllerHand::Right :
				{
					RightComponent = HandComponent;
					break;
				}
			default :
				{
					break;
				}
			}
		}
	}
	
}

bool UXRReplicationComponent::IsLocallySimulated() const
{
	APawn * Pawn = GetOwner<APawn>();
	if (ensure(Pawn))
	{
		if (Pawn->IsPlayerControlled() && Pawn->IsLocallyControlled())
		{
			return true;
		}
	}
	return false;
}


// Called every frame
void UXRReplicationComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetNetMode() != NM_Standalone)
	{
		ReplicateTime += DeltaTime;

		if (ReplicateTime >= ReplicationFrequency->GetValue())
		{
			if (IsLocallySimulated())
			{
				ReplicateXRPositionRotation_Server(HeadComponent->GetRelativeLocation(), HeadComponent->GetRelativeRotation(),
					LeftComponent->GetRelativeLocation(), LeftComponent->GetRelativeRotation(),
					RightComponent->GetRelativeLocation(), RightComponent->GetRelativeRotation(), NextSequence++);
			}
			else
			{
				if (ReplicatedPositions.Num() == 1)
				{
					//extrapolate new position
					const float Time = ReplicationFrequency->GetValue() * 2;
					const FVector NewLeftPosition = FMath::Lerp(PreviousReplicatedPosition.LeftPosition, ReplicatedPositions[0].LeftPosition, Time);
					const FQuat NewLeftRotation = FMath::Lerp(PreviousReplicatedPosition.LeftRotation.Quaternion(), ReplicatedPositions[0].LeftRotation.Quaternion(), Time);
					const FVector NewRightPosition = FMath::Lerp(PreviousReplicatedPosition.RightPosition, ReplicatedPositions[0].RightPosition, Time);
					const FQuat NewRightRotation = FMath::Lerp(PreviousReplicatedPosition.LeftRotation.Quaternion(),ReplicatedPositions[0].LeftRotation.Quaternion(), Time);
					const FVector NewHeadPosition = FMath::Lerp(PreviousReplicatedPosition.HeadPosition, ReplicatedPositions[0].HeadPosition, Time);
					const FQuat NewHeadRotation = FMath::Lerp(PreviousReplicatedPosition.HeadRotation.Quaternion(),ReplicatedPositions[0].HeadRotation.Quaternion(), Time);
					ReplicatedPositions.Add(FXRReplicatedPosition(NewHeadPosition, NewHeadRotation.Rotator(), NewLeftPosition,
						NewLeftRotation.Rotator(), NewRightPosition, NewRightRotation.Rotator(),
						ReplicatedPositions[0].Sequence+1));
				}
				PreviousReplicatedPosition = ReplicatedPositions.Pop();
				
			}
			ReplicateTime = 0.0f;
		}

		//move proxy to match next position
		const float Time = ReplicateTime / ReplicationFrequency->GetValue();
		const FVector NewLeftPosition = FMath::Lerp(PreviousReplicatedPosition.LeftPosition, ReplicatedPositions[0].LeftPosition, Time);
		const FQuat NewLeftRotation = FMath::Lerp(PreviousReplicatedPosition.LeftRotation.Quaternion(), ReplicatedPositions[0].LeftRotation.Quaternion(), Time);
		const FVector NewRightPosition = FMath::Lerp(PreviousReplicatedPosition.RightPosition, ReplicatedPositions[0].RightPosition, Time);
		const FQuat NewRightRotation = FMath::Lerp(PreviousReplicatedPosition.LeftRotation.Quaternion(),ReplicatedPositions[0].LeftRotation.Quaternion(), Time);
		const FVector NewHeadPosition = FMath::Lerp(PreviousReplicatedPosition.HeadPosition, ReplicatedPositions[0].HeadPosition, Time);
		const FQuat NewHeadRotation = FMath::Lerp(PreviousReplicatedPosition.HeadRotation.Quaternion(),ReplicatedPositions[0].HeadRotation.Quaternion(), Time);
		LeftProxyComponent->SetRelativeLocation(NewLeftPosition);
		LeftProxyComponent->SetRelativeRotation(NewLeftRotation);
		RightProxyComponent->SetRelativeLocation(NewRightPosition);
		RightProxyComponent->SetRelativeRotation(NewRightRotation);
		HeadProxyComponent->SetRelativeLocation(NewHeadPosition);
		HeadProxyComponent->SetRelativeRotation(NewHeadRotation);
	}
	else
	{
		FHitResult Result;
		//update Hand proxies
		FVector Movement = UUtilityStatics::GetVectorTo(LeftProxyComponent->GetComponentLocation(), LeftComponent->GetComponentLocation());
		if (!LeftProxyComponent->MoveComponent(Movement,LeftComponent->GetComponentRotation().Quaternion(),true, &Result))
		{
			LeftProxyComponent->SetWorldLocation(Result.ImpactPoint);
			LeftProxyComponent->SetWorldRotation(LeftComponent->GetComponentRotation());
		}
		Movement = UUtilityStatics::GetVectorTo(RightProxyComponent->GetComponentLocation(), RightComponent->GetComponentLocation());
		if (!RightProxyComponent->MoveComponent(Movement,RightComponent->GetComponentRotation().Quaternion(),true, &Result))
		{
			RightProxyComponent->SetWorldLocation(Result.ImpactPoint);
			RightProxyComponent->SetWorldRotation(RightComponent->GetComponentRotation());
		}
		if (HeadProxyComponent)
		{
			HeadProxyComponent->SetWorldLocation(HeadComponent->GetComponentLocation());
			HeadProxyComponent->SetWorldRotation(HeadComponent->GetComponentRotation());
		}
	}
}

FTransform UXRReplicationComponent::GetHeadTransform() const
{
	if (ensure(HeadComponent))
	{
		return HeadComponent->GetComponentTransform();
	}
	return FTransform();
}

FTransform UXRReplicationComponent::GetLeftTransform() const
{
	if (ensure(LeftComponent))
	{
		return LeftComponent->GetComponentTransform();
	}
	return FTransform();
}

FTransform UXRReplicationComponent::GetRightTransform() const
{
	if (ensure(RightComponent))
	{
		return RightComponent->GetComponentTransform();
	}
	return FTransform();
}

void UXRReplicationComponent::ReplicateXRPositionRotation_Server_Implementation(FVector HeadPosition,
                                                                                FRotator HeadRotation, FVector LeftHandPosition, FRotator LeftHandRotation, FVector RightHandPosition,
                                                                                FRotator RightHandRotation, int Sequence)
{
	ReplicateXRPositionRotation_Multicast(HeadPosition, HeadRotation, LeftHandPosition, LeftHandRotation, RightHandPosition, RightHandRotation, Sequence);
}

void UXRReplicationComponent::ReplicateXRPositionRotation_Multicast_Implementation(FVector HeadPosition,
	FRotator HeadRotation, FVector LeftHandPosition, FRotator LeftHandRotation, FVector RightHandPosition,
	FRotator RightHandRotation, int Sequence)
{
	AddReplicatedPosition(HeadPosition, HeadRotation, LeftHandPosition, LeftHandRotation, RightHandPosition, RightHandRotation, Sequence);
}