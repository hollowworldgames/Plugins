// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "NativeGameplayTags.h"
#include "Calculation/CombatCalculationBase.h"
#include "FantasyDamageExecutionCalculation.generated.h"

UCLASS()
class FANTASYCHARACTER_API UFantasyDamageExecutionCalculation : public UCombatCalculationBase
{
	GENERATED_BODY()
public :
	UFantasyDamageExecutionCalculation();
protected :
	virtual float GetDamageBoost(const FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const override;
	virtual float GetMitigation(const FGameplayTag DamageType, const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		const FAggregatorEvaluateParameters& EvaluateParameters) const override;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(PhysicalMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ElementalMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MagicalMitigation);
};
