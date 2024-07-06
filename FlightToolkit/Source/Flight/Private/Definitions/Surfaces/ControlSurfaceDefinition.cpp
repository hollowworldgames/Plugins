// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Surfaces/ControlSurfaceDefinition.h"
#include "PhysicStatics.h"

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
	Force = Up * ControlValue;
	Rotation = UPhysicStatics::GetRotationFromForce(Location, FVector::Zero(), Force);
}

void UControlSurfaceDefinition::TickControl(float AirPressure, TObjectPtr<USkeletalMeshComponent> Root)
{
	FQuat Rotate = Root->GetBoneQuaternion(Bone);
	switch(ControlType)
	{
	case EControlType::Aileron :
	case EControlType::Elevator :
	case EControlType::Taileron :
		{
			Force = Rotate.GetUpVector() * ControlValue * MaxForce * ForceFromAirspeed.GetValueAtLevel(Root->GetComponentVelocity().Length());
			Root->AddForceAtLocation(Force, Root->GetBoneLocation(Bone), Bone);
			break;
		}
	case EControlType::Rudder :
		{
			Force = Rotate.GetRightVector() * ControlValue * MaxForce * ForceFromAirspeed.GetValueAtLevel(Root->GetComponentVelocity().Length());
			Root->AddForceAtLocation(Force, Root->GetBoneLocation(Bone), Bone);
			break;
		}
	default :
		{
			break;
		}
	}
}
