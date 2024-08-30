// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculation/CombatDOTCalculationBase.h"

#include "Attributes/RPGAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UCombatDOTCalculationBase::UCombatDOTCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, BlockChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, BlockValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, ParryChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, GlancingBlowChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Resistance1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Resistance2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Resistance3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Resistance4, Target, false, true);
	
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalValue, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Accuracy, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Penetration, Source, false, true);
}

void UCombatDOTCalculationBase::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(DamageBoost1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(DamageBoost2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(DamageBoost3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(DamageBoost4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Accuracy, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Penetration, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(BlockChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BlockValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ParryChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EvadeChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlancingBlowChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDefense, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Resistance1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Resistance2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Resistance3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Resistance4, ExecutionParams);

	const float AbilityBonus = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(AbilityDamageBonusTag, true, 1);
	const float MinDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MinDamageTag, true, 0) * (1 + AbilityBonus);
	const float MaxDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MaxDamageTag, true, 0) * (1 + AbilityBonus);
	float Resistance = 0;
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	if(DamageTag.MatchesTag(DamageTypeTag1))
	{
		Resistance = Resistance1;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag2))
	{
		Resistance = Resistance2;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag3))
	{
		Resistance = Resistance3;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag4))
	{
		Resistance = Resistance4;
	}

	
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
	return DamageTypeTag1;
}
