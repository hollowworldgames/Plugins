// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "UObject/Object.h"
#include "GameplayEffectExecutionCalculation.h"
#include "SpaceCraftExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACECRAFT_API USpaceCraftExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	USpaceCraftExecutionCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ReactorHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxReactorHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ReactorBoost);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ReactorLevel);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BatteryHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxBatteryHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BatteryLevel);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BatteryBoost);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BatteryPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxBatteryPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldLevel);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldOn);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldBoost);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxFrontShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxBackShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponDistribution);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldDistribution);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EngineDistribution);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EngineHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxEngineHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EngineLevel);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EngineOn);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EngineBoost);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat ReactorOutput;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat DamageEfficacy;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat ShieldRecharge;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat EngineOutput;
};
