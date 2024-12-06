// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculation/CombatDOTCalculationBase.h"

#include "Attributes/RPGAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UCombatDOTCalculationBase::UCombatDOTCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, BlockChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, BlockValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, ParryChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, GlancingBlowChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, Resistance1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, Resistance2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, Resistance3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, Resistance4, Target, false, true);
	
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, DamageBoost1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, DamageBoost2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, DamageBoost3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, DamageBoost4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, CriticalValue, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, HitChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, Penetration, Source, false, true);
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
	GET_EXECUTION_ATTRIBUTE(HitChance, ExecutionParams);
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
	FVector4f Resistance = FVector4f(Resistance1, Resistance2, Resistance3, Resistance4);
	const float Damage1 = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(DamageTypeTag1,false, 0);
	const float Damage2 = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(DamageTypeTag2,false, 0);
	const float Damage3 = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(DamageTypeTag3,false, 0);
	const float Damage4 = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(DamageTypeTag4,false, 0);
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	float BaseDamage = FMath::RandRange(MinDamage, MaxDamage);
	FVector4f Damage(Damage1 * BaseDamage, Damage2 * BaseDamage, Damage3 * BaseDamage, Damage4 * BaseDamage);
	
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
