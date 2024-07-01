// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Components/DoorMovementComponent.h"

// Sets default values for this component's properties
UDoorMovementComponent::UDoorMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UDoorMovementComponent::Open()
{
	if(State == EDoorState::EDoorState_Closed)
	{
		if(OnOpen.IsBound())
		{
			OnOpen.Broadcast();
		}
		State = EDoorState::EDoorState_Opening;
		ChangeDelta = 0;
	}
}

void UDoorMovementComponent::Close()
{
	if(State == EDoorState::EDoorState_Opened)
	{
		if(OnClose.IsBound())
		{
			OnClose.Broadcast();
		}
		State = EDoorState::EDoorState_Closing;
		ChangeDelta = 0;
	}
}

void UDoorMovementComponent::SetOpened()
{
	GetOwner()->SetActorLocation(OpenPosition);
	GetOwner()->SetActorRotation(OpenRotation);
	State = EDoorState::EDoorState_Opened;
}

void UDoorMovementComponent::SetClosed()
{
	GetOwner()->SetActorLocation(ClosePosition);
	GetOwner()->SetActorRotation(CloseRotation);
	State = EDoorState::EDoorState_Closed;
}


// Called when the game starts
void UDoorMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDoorMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch(State)
	{
	case EDoorState::EDoorState_Closing:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				GetOwner()->SetActorLocation(FMath::VInterpTo(GetOwner()->GetActorLocation(), ClosePosition, DeltaTime, ChangeTime));
				GetOwner()->SetActorRotation(FMath::RInterpTo(GetOwner()->GetActorRotation(), CloseRotation, DeltaTime, ChangeTime));
			}
			else
			{
				SetClosed();
				if(OnClosed.IsBound())
				{
					OnClosed.Broadcast();
				}
			}
			break;
		}
	case EDoorState::EDoorState_Opening:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				GetOwner()->SetActorLocation(FMath::VInterpTo(GetOwner()->GetActorLocation(), OpenPosition, DeltaTime, ChangeTime));
				GetOwner()->SetActorRotation(FMath::RInterpTo(GetOwner()->GetActorRotation(), OpenRotation, DeltaTime, ChangeTime));
			}
			else
			{
				SetOpened();
				if(OnOpened.IsBound())
				{
					OnOpened.Broadcast();
				}
			}
			break;
		}
	default:
		{
			break;
		}
	}
}

