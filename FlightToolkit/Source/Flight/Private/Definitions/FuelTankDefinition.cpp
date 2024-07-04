// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions\FuelTankDefinition.h"

float UFuelTankDefinition::GetPercent() const
{
	if(MaxFuel != 0)
	{
		return Fuel / MaxFuel;
	}
	return 0;
}

EResource UFuelTankDefinition::GetProvided()
{
	return EResource::Fuel;
}

float UFuelTankDefinition::Consume(float Amount)
{
	Fuel = FMath::Clamp(Fuel - Amount, 0, MaxFuel);
	return Amount;
}

void UFuelTankDefinition::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
	
}

EResource UFuelTankDefinition::GetNeededResource()
{
	return EResource::Fuel;
}

float UFuelTankDefinition::GetNeeded()
{
	return 0.1f;
}

float UFuelTankDefinition::Provided(float Amount)
{
	Fuel = FMath::Clamp(Fuel + Amount, 0, MaxFuel);
	return Amount;
}

FGameplayTag UFuelTankDefinition::GetComponentTag()
{
	return GetComponentId();
}
