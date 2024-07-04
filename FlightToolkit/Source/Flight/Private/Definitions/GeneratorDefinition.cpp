// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/GeneratorDefinition.h"

float UGeneratorDefinition::Consume(float Amount)
{
	Power = FMath::Clamp(Power - Amount, 0, PowerOutput);
	return Amount;
}

void UGeneratorDefinition::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
}

void UGeneratorDefinition::Generate(float RPM)
{
	if(RPM > NeededRPM)
	{
		Power = PowerOutput;
	}
}
