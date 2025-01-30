// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Effects/FantasyDOTExecutionCalculation.h"
#include "Attributes/FantasyCombatAttributeSet.h"

float UFantasyDOTExecutionCalculation::GetDamageBoost(const FGameplayTag DamageType,
	const FGameplayEffectSpec& Spec) const
{
	if (DamageType.MatchesTag(PhysicalTypeTag))
	{
		return Spec.GetSetByCallerMagnitude(PhysicalBoostTag);
	}
	if (DamageType.MatchesTag(ElementalTypeTag))
	{
		return Spec.GetSetByCallerMagnitude(ElementalBoostTag);
	}
	if (DamageType.MatchesTag(MagicalTypeTag))
	{
		return Spec.GetSetByCallerMagnitude(MagicalBoostTag);
	}
	return Super::GetDamageBoost(DamageType, Spec);
}

float UFantasyDOTExecutionCalculation::GetResistance(FGameplayTag DamageType,
	const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	if (DamageType.MatchesTag(PhysicalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(PhysicalResistance, ExecutionParams);
		return PhysicalResistance;
	}
	if (DamageType.MatchesTag(ElementalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(ElementalResistance, ExecutionParams);
		return ElementalResistance;
	}
	if (DamageType.MatchesTag(MagicalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(MagicalResistance, ExecutionParams);
		return MagicalResistance;
	}
	return Super::GetResistance(DamageType, ExecutionParams, EvaluateParameters);
}

UFantasyDOTExecutionCalculation::UFantasyDOTExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, PhysicalResistance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, ElementalResistance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, MagicalResistance, Target, false, true);
}

