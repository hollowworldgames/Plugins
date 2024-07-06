// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Damage/Public/DamageableDefinition.h"
#include "LiftSurfaceDefinition.generated.h"

class UControlSurfaceDefinition;
/**
 * 
 */
UCLASS()
class FLIGHT_API ULiftSurfaceDefinition : public UDamageableDefinition
{
	GENERATED_BODY()
public :
	virtual void TickSurface(float AirPressure, FVector WindDirection, FVector Forward, FVector Up, float Airspeed);
	virtual void TickSurface(float AirPressure, USkeletalMeshComponent * Root);
	void AddControl(const TObjectPtr<UControlSurfaceDefinition>& Control);
	FVector GetForce() const { return Force; }
	FVector GetRotation() const { return Rotation; }
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	FVector Force;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	FVector Rotation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Alpha = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TObjectPtr<UCurveTable> DataTable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	TArray<TObjectPtr<UControlSurfaceDefinition>> AttachedControls;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	double SurfaceArea = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	double MaxAlpha = 20;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FName Bone;
};
