// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Surfaces/ControlSurfaceDefinition.h"

float UControlSurfaceDefinition::GetNeeded()
{
	return 1;
}

float UControlSurfaceDefinition::Provided(float Amount)
{
	HydraulicPressure = Amount;
	return Amount;
}

void UControlSurfaceDefinition::SetControlValue(float Value)
{
	ControlValue = Value * HydraulicPressure;
}

void UControlSurfaceDefinition::TickControl(float AirPressure, float Airspeed, FVector WindDirection, FVector Forward,
	FVector Up)
{
	
}
