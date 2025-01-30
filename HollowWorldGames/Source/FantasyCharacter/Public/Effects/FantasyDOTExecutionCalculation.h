// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Calculation/CombatDOTCalculationBase.h"
#include "FantasyDOTExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYCHARACTER_API UFantasyDOTExecutionCalculation : public UCombatDOTCalculationBase
{
	GENERATED_BODY()
public :
	UFantasyDOTExecutionCalculation();
protected :
    virtual float GetDamageBoost(const FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const override;
	virtual float GetResistance(FGameplayTag DamageTag, const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		const FAggregatorEvaluateParameters& EvaluateParameters) const override;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(PhysicalResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ElementalResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MagicalResistance);
};
