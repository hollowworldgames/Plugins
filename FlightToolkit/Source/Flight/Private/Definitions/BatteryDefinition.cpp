// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/BatteryDefinition.h"

float UBatteryDefinition::Consume(float Amount)
{
	Power = FMath::Clamp(Power - Amount, 0, MaxPower);
	return Amount;
}

void UBatteryDefinition::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
}

void UBatteryDefinition::AddPower(float Amount)
{
	Power = FMath::Clamp(Power + Amount, 0, MaxPower);
}