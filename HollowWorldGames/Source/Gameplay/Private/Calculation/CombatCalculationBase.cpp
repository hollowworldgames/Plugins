// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculation/CombatCalculationBase.h"

#include "GameplayUtilities.h"
#include "Attributes/RPGAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UCombatCalculationBase::UCombatCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, BlockChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, BlockValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, ParryChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, GlancingBlowChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Mitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Mitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Mitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Mitigation4, Target, false, true);
	
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, DamageBoost4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, CriticalValue, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Accuracy, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Penetration, Source, false, true);
}

void UCombatCalculationBase::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
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
	GET_EXECUTION_ATTRIBUTE(Mitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation4, ExecutionParams);

	const float AbilityBonus = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(AbilityDamageBonusTag, true, 1);
	const float MinDamage = ExecutionParams.GetOwningSpec().SetByCallerTagMagnitudes[MinDamageTag] * (1 + AbilityBonus);
	const float MaxDamage = ExecutionParams.GetOwningSpec().SetByCallerTagMagnitudes[MaxDamageTag] * (1 + AbilityBonus);
	
	float Damage = 100;
	float Mitigation = 0;
	float DamageBoost = 0;
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	if(DamageTag.MatchesTag(DamageTypeTag1))
	{
		Mitigation = Mitigation1;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag2))
	{
		Mitigation = Mitigation2;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag3))
	{
		Mitigation = Mitigation3;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag4))
	{
		Mitigation = Mitigation4;
	}

	Damage *= (DamageBoost / 1000);
	
	ECombatRollResult Result = UGameplayUtilities::DoCombatRoll(Damage, Accuracy, Mitigation, BlockChance, BlockValue, ParryChance,
		EvadeChance, GlancingBlowChance, CriticalChance, CriticalDefense, CriticalValue, Penetration);

	
}

FGameplayTag UCombatCalculationBase::GetDamageTypeTag(const FGameplayEffectSpec& Spec) const
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
