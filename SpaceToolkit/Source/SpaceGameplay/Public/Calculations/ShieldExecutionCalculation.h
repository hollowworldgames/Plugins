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
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldFrontHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldMaxFrontHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldBackHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldMaxBackHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(PowerToHitPoints);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldPower);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Curves)
	FScalableFloat Efficiency;
};
