// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Engines/EngineDefinition.h"

#include "UtilityStatics.h"
#include "Interfaces/Source.h"

void UEngineDefinition::Start()
{
	if(State == EEngineState::Off)
	{
		State = EEngineState::Starting;
	}
}

void UEngineDefinition::Stop()
{
	if(State == EEngineState::Running)
	{
		State = EEngineState::Stopping;
	}
}

void UEngineDefinition::TickEngine(float DeltaTime, float Airpressure, float Airspeed)
{
	Throttle = UUtilityStatics::MoveTowardTargetValue(Throttle, ThrottleTarget, 1, DeltaTime, 0, 1);
	Boost = UUtilityStatics::MoveTowardTargetValue(Boost, BoostTarget, 1, DeltaTime, 0, 1);
}

EResource UEngineDefinition::GetNeededResource()
{
	return EResource::Fuel;
}

float UEngineDefinition::GetNeeded()
{
	return FuelFromThrottle.GetValueAtLevel(Throttle);
}

float UEngineDefinition::Provided(float Amount)
{
	Fuel = Amount;
	return Amount;
}

FGameplayTag UEngineDefinition::GetComponentTag()
{
	return GetComponentId();
}

void UEngineDefinition::SetThrottle(float NewThrottle)
{
	ThrottleTarget = NewThrottle;
}

void UEngineDefinition::SetBoost(float newBoost)
{
	BoostTarget = newBoost;
}
