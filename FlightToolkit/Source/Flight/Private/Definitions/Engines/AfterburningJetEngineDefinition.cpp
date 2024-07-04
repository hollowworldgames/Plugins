// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Engines/AfterburningJetEngineDefinition.h"

void UAfterburningJetEngineDefinition::TickEngine(float DeltaTime, float Airpressure, float Airspeed)
{
	Super::TickEngine(DeltaTime, Airpressure, Airspeed);
	if(BurnerFuel > 0)
	{
		Force += BurnerThrust.GetValueAtLevel(BurnerFuel);
	}
}

float UAfterburningJetEngineDefinition::GetNeeded()
{
	float Needed = Super::GetNeeded();
	if(Boost > 0)
	{
		Needed += BurnerNeed.GetValueAtLevel(Boost);
	}
	return Needed;
}

float UAfterburningJetEngineDefinition::Provided(float Amount)
{
	Fuel = FMath::Min(Amount, MaxFuel);
	BurnerFuel = FMath::Clamp(Amount - MaxFuel, 0, Amount);
	return Super::Provided(Amount);
}
