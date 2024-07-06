// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Surfaces/LiftSurfaceDefinition.h"

#include "PhysicStatics.h"
#include "Quaternion.h"
#include "SkeletalMeshAttributes.h"
#include "UtilityStatics.h"
#include "Definitions/Surfaces/ControlSurfaceDefinition.h"

void ULiftSurfaceDefinition::TickSurface(float Airpressure, FVector WindDirection, FVector Forward, FVector Up,
                                         float Airspeed)
{
	FVector Right = Forward.Cross(Up);
	Alpha = UUtilityStatics::ComputeAOA(Forward, WindDirection, Right);
	float NormalizedAlpha = FMath::Clamp(Alpha / MaxAlpha, -1, 1);
	double LastPart = ((Airpressure * Airspeed * Airspeed) / 2.0) * (SurfaceArea * GetEfficiency());

	FVector LiftDirection = WindDirection.Cross(Right);

	FString Context;
	float Flaps = 0;
	float Slats = 0;
	float Brakes = 0;
	FVector ControlForce = FVector::Zero();

	for(TObjectPtr<UControlSurfaceDefinition> Control : AttachedControls)
	{
		switch(Control->GetControlType())
		{
		case EControlType::Flap :
			{
				Flaps = FMath::Floor(Control->GetControlValue());
				break;
			}
		case EControlType::Slat :
			{
				Slats = FMath::Floor(Control->GetControlValue());
				break;
			}
		case EControlType::Rudder :
			{
				ControlForce += Right * Control->GetForce();
				break;
			}
		case EControlType::Brake :
			{
				Brakes = FMath::Floor(Control->GetControlValue());
				break;
			}
		default :
			{
				ControlForce += Up * Control->GetForce();
				break;
			}
		}
	}
	
	FName LiftName(FString::Printf(TEXT("LiftCoefficient_%f_%f_%f"), Slats, Flaps, Brakes));
	FName DragName(FString::Printf(TEXT("LiftCoefficient_%f_%f_%f"), Slats, Flaps, Brakes));
	FRealCurve * LiftCoefficient = DataTable->FindCurve(LiftName,Context);
	FRealCurve * DragCoefficient = DataTable->FindCurve(DragName,Context);
	
	FVector Lift = LiftDirection * (LiftCoefficient->Eval(NormalizedAlpha)) * LastPart;
	FVector Drag = WindDirection * (DragCoefficient->Eval(NormalizedAlpha))* LastPart;
	Force = Lift + Drag + ControlForce;
	Rotation = UPhysicStatics::GetRotationFromForce(Location, FVector::Zero(), Force);
}

void ULiftSurfaceDefinition::TickSurface(float AirPressure, USkeletalMeshComponent* Root)
{
	FVector Velocity = Root->GetComponentVelocity();
	FVector WindDirection = -Velocity;
	FQuat Rotate = Root->GetBoneQuaternion(Bone);
	FVector Forward = Rotate.GetForwardVector();
	FVector Up = Rotate.GetUpVector();
	FVector Right = Rotate.GetRightVector();
	double AirSpeedSquared = Velocity.SquaredLength();

	Alpha = UUtilityStatics::ComputeAOA(Forward, WindDirection, Right);
	float NormalizedAlpha = FMath::Clamp(Alpha / MaxAlpha, -1, 1);
	double LastPart = ((AirPressure * AirSpeedSquared) / 2.0) * (SurfaceArea * GetEfficiency());

	FVector LiftDirection = WindDirection.Cross(Right);

	FString Context;
	float Flaps = 0;
	float Slats = 0;
	float Brakes = 0;
	FVector ControlForce = FVector::Zero();

	for(TObjectPtr<UControlSurfaceDefinition> Control : AttachedControls)
	{
		switch(Control->GetControlType())
		{
		case EControlType::Flap :
			{
				Flaps = FMath::Floor(Control->GetControlValue());
				break;
			}
		case EControlType::Slat :
			{
				Slats = FMath::Floor(Control->GetControlValue());
				break;
			}
		case EControlType::Rudder :
			{
				ControlForce += Right * Control->GetForce();
				break;
			}
		case EControlType::Brake :
			{
				Brakes = FMath::Floor(Control->GetControlValue());
				break;
			}
		default :
			{
				ControlForce += Up * Control->GetForce();
				break;
			}
		}
	}
	
	FName LiftName(FString::Printf(TEXT("LiftCoefficient_%f_%f_%f"), Slats, Flaps, Brakes));
	FName DragName(FString::Printf(TEXT("LiftCoefficient_%f_%f_%f"), Slats, Flaps, Brakes));
	FRealCurve * LiftCoefficient = DataTable->FindCurve(LiftName,Context);
	FRealCurve * DragCoefficient = DataTable->FindCurve(DragName,Context);
	
	FVector Lift = LiftDirection * (LiftCoefficient->Eval(NormalizedAlpha)) * LastPart;
	FVector Drag = WindDirection * (DragCoefficient->Eval(NormalizedAlpha))* LastPart;
	Force = Lift + Drag + ControlForce;
	Root->AddForceAtLocation(Force, Root->GetBoneLocation(Bone), Bone);
}

void ULiftSurfaceDefinition::AddControl(const TObjectPtr<UControlSurfaceDefinition>& Control)
{
	AttachedControls.Add(Control);
}
