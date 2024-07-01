// Copyright (c) 2023 Hollow World Games llc. All rights reserved.


#include "Components/RaiseLowerComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
URaiseLowerComponent::URaiseLowerComponent() : UStaticMeshComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called every frame
void URaiseLowerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(DelayDelta > 0)
	{
		DelayDelta -=  DeltaTime;
		if(DelayDelta < 0)
		{
			if(StartSound.IsBound())
			{
				StartSound.Broadcast();
			}
		}
		return;
	}
	switch(State)
	{
	case ERaiseLowerState::ERaiseLowerState_Lowering:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				SetRelativeLocation(FMath::Lerp(RaisePosition, LowerPosition, ChangeDelta / ChangeTime));
				SetRelativeRotation(UKismetMathLibrary::RLerp(RaiseRotation, LowerRotation, ChangeDelta / ChangeTime, false));
			}
			else
			{
				SetLowered();
				if(OnLowered.IsBound())
				{
					OnLowered.Broadcast();
				}
			}
			break;
		}
	case ERaiseLowerState::ERaiseLowerState_Rising:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				SetRelativeLocation(FMath::Lerp(LowerPosition, RaisePosition, ChangeDelta / ChangeTime));
				SetRelativeRotation(UKismetMathLibrary::RLerp(LowerRotation, RaiseRotation, ChangeDelta / ChangeTime, false));
			}
			else
			{
				SetRaised();
				if(OnRaised.IsBound())
				{
					OnRaised.Broadcast();
				}
			}
			break;
		}
	}
}

void URaiseLowerComponent::Raise()
{
	if(State == ERaiseLowerState::ERaiseLowerState_Lowered)
	{
		if(OnRaise.IsBound())
		{
			OnRaise.Broadcast();
		}
		State = ERaiseLowerState::ERaiseLowerState_Rising;
		ChangeDelta = 0;
		DelayDelta = ChangeDelayRaise;
	}
}

void URaiseLowerComponent::Lower()
{
	if(State == ERaiseLowerState::ERaiseLowerState_Raised)
	{
		if(OnLower.IsBound())
		{
			OnLower.Broadcast();
		}
		State = ERaiseLowerState::ERaiseLowerState_Lowering;
		ChangeDelta = 0;
		DelayDelta = ChangeDelayLower;
	}
}

void URaiseLowerComponent::SetRaised()
{
	SetRelativeLocation(RaisePosition);
	SetRelativeRotation(RaiseRotation);
	State = ERaiseLowerState::ERaiseLowerState_Raised;
}

void URaiseLowerComponent::SetLowered()
{
	SetRelativeLocation(LowerPosition);
	SetRelativeRotation(LowerRotation);
	State = ERaiseLowerState::ERaiseLowerState_Lowered;
}

