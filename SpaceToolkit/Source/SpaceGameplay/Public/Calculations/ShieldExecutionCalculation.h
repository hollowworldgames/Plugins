// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ShieldExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAMEPLAY_API UShieldExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UShieldExecutionCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected:
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxFrontShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxBackShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxRightShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxLeftShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(PowerToHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldFaces);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Curves)
	FScalableFloat Efficiency;
};
