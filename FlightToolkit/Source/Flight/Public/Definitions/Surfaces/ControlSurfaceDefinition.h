// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "ControlSurfaceDefinition.generated.h"

UENUM(BlueprintType)
enum class EControlType : uint8
{
	Slat,
	Flap,
	Flaperon,
	Brake,
	Aileron,
	Elevator,
	Taileron,
	Rudder,
	Canard,
};

UCLASS()
class FLIGHT_API UControlSurfaceDefinition : public UDamageableDefinition ,public IConsumer
{
	GENERATED_BODY()
public :
	virtual EResource GetNeededResource() override { return EResource::Hydraulic; }
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
	virtual FGameplayTag GetComponentTag() override { return GetComponentId(); }
	EControlType GetControlType() const { return ControlType; }
	virtual void SetControlValue(float Value);
	virtual float GetControlValue() const { return ControlValue; }
	virtual void TickControl(float AirPressure, float Airspeed, FVector WindDirection, FVector Forward, FVector Up);
	virtual void TickControl(float AirPressure, TObjectPtr<USkeletalMeshComponent> Root);
	FVector GetForce() const { return Force; }
	FVector GetRotation() const { return Rotation; }
	FGameplayTag GetParentSurface() const { return ParentSurface; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	EControlType ControlType;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float ControlValue = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	FVector Force = FVector::Zero();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag ParentSurface;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	bool Right = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float HydraulicPressure = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	FVector Rotation = FVector::Zero();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FName Bone;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat ForceFromAirspeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	double MaxForce = 100;
};
