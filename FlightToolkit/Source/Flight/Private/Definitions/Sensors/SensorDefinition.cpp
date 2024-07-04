// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Sensors/SensorDefinition.h"

void USensorDefinition::SensorTick(float DeltaTime, AActor * Owner)
{
	
}

float USensorDefinition::GetNeeded()
{
	return 0.1f;
}

float USensorDefinition::Provided(float Amount)
{
	
	return Amount;
}
