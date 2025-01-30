// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Effects/FantasyDamageExecutionCalculation.h"
#include "AttributeMacros.h"
#include "Attributes/FantasyCombatAttributeSet.h"

UFantasyDamageExecutionCalculation::UFantasyDamageExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, PhysicalMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, ElementalMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFantasyCombatAttributeSet, MagicalMitigation, Target, false, true);
}

float UFantasyDamageExecutionCalculation::GetDamageBoost(const FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const
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

float UFantasyDamageExecutionCalculation::GetMitigation(const FGameplayTag DamageType,
	const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	if (DamageType.MatchesTag(PhysicalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(PhysicalMitigation, ExecutionParams);
		return PhysicalMitigation;
	}
	if (DamageType.MatchesTag(ElementalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(ElementalMitigation, ExecutionParams);
		return ElementalMitigation;
	}
	if (DamageType.MatchesTag(MagicalTypeTag))
	{
		GET_EXECUTION_ATTRIBUTE(MagicalMitigation, ExecutionParams);
		return MagicalMitigation;
	}
	return Super::GetMitigation(DamageType, ExecutionParams, EvaluateParameters);
}

