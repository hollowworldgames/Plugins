// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculation/CombatDOTCalculationBase.h"
#include "Attributes/RPGAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UCombatDOTCalculationBase::UCombatDOTCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, GlancingBlowChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalValue, Source, false, true);
}

void UCombatDOTCalculationBase::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(CriticalChance, ExecutionParams);
    GET_EXECUTION_ATTRIBUTE(CriticalValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDefense, ExecutionParams);
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	const float AbilityBonus = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(AbilityDamageBoostTag, true, 1);
	const float MinDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MinDamageTag, true, 0) * (1 + AbilityBonus);
	const float MaxDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MaxDamageTag, true, 0) * (1 + AbilityBonus);
	float Resistance = GetResistance(DamageTag, ExecutionParams, EvaluateParameters);

	const float BaseDamage = FMath::RandRange(MinDamage, MaxDamage);
	const float Damage = BaseDamage * GetDamageBoost(DamageTag, ExecutionParams.GetOwningSpec());

	float IncomingDamage = UGameplayUtilities::ApplyMitigation(Damage, Resistance);

	ECombatRollResult Result = Hit;

	if (UGameplayUtilities::ApplyCriticalHit(IncomingDamage, CriticalChance, CriticalDefense, CriticalValue))
	{
		Result = CriticalHit;
	}
	
	SourceComponent->ReportDamage(Result, IncomingDamage, Source, Target, DamageTag);
	TargetComponent->ReportDamage(Result, IncomingDamage, Source, Target, DamageTag);
	
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, IncomingDamage, OutExecutionOutput);
}

FGameplayTag UCombatDOTCalculationBase::GetDamageTypeTag(const FGameplayEffectSpec& Spec) const
{
	FGameplayTagContainer ActorTags;
	FGameplayTagContainer SpecTags;

	Spec.GetContext().GetOwnedGameplayTags(ActorTags, SpecTags);
	//get damage type tag
	for(const FGameplayTag Tag : SpecTags.GetGameplayTagArray())
	{
		if(Tag.MatchesTag(DamageTypeTag))
		{
			return Tag;
		}
	}
	return FGameplayTag();
}

float UCombatDOTCalculationBase::GetDamageBoost(FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const
{
	return 0;
}

float UCombatDOTCalculationBase::GetDamage(FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const
{
	return Spec.GetSetByCallerMagnitude(DamageType, true, 0);
}

float UCombatDOTCalculationBase::GetResistance(FGameplayTag DamageTag,
	const FGameplayEffectCustomExecutionParameters& Spec, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	return 0;
}
