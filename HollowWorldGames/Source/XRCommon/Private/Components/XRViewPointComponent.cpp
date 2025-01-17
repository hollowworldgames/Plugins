// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/XRViewPointComponent.h"
#include "Actors/XRHandActor.h"
#include "MotionControllerComponent.h"
#include "Utility/XRUtilityStatics.h"

// Sets default values for this component's properties
UXRViewPointComponent::UXRViewPointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UXRViewPointComponent::BeginPlay()
{
	Super::BeginPlay();
	LeftHand = Cast<UMotionControllerComponent>(GetChildComponent(1));
	RightHand = Cast<UMotionControllerComponent>(GetChildComponent(2));
	if (LeftHand && RightHand)
	{
		LeftHand->Deactivate();
		RightHand->Deactivate();
	}
}

void UXRViewPointComponent::MakeActive()
{
	Super::MakeActive();
	if (UXRUtilityStatics::IsXRRunning())
	{
		LeftHand->Activate();
		RightHand->Activate();
		if (Avatar)
		{
			
		}
		else
		{
			LeftHandActor = UXRUtilityStatics::GetXRHandActor(this, EHand::Left);
			if (LeftHandActor)
			{
				LeftHandActor->SetActorLocation(LeftHand->GetComponentLocation());
				LeftHandActor->SetActorRotation(LeftHand->GetComponentRotation());
				LeftHandActor->AttachToComponent(LeftHand, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			}
			
			RightHandActor = UXRUtilityStatics::GetXRHandActor(this, EHand::Right);
			if (RightHandActor)
			{
				RightHandActor->SetActorLocation(RightHand->GetComponentLocation());
				RightHandActor->SetActorRotation(RightHand->GetComponentRotation());
				RightHandActor->AttachToComponent(RightHand, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			}
		}
	}
	else
	{
		LeftHand->Deactivate();
		RightHand->Deactivate();
	}
}

void UXRViewPointComponent::MakeInactive()
{
	Super::MakeInactive();
	if (UXRUtilityStatics::IsXRRunning())
	{
		LeftHand->Deactivate();
		RightHand->Deactivate();
	}
}

UMotionControllerComponent* UXRViewPointComponent::GetMotionController(EHand Hand) const
{
	switch (Hand)
	{
	case EHand::Left:
		return LeftHand;
	case EHand::Right:
		return RightHand;
	}
	return nullptr;
}

