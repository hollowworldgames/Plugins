// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "FuelExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAMEPLAY_API UFuelExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UFuelExecutionCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Fuel);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FuelNeeded);
};
