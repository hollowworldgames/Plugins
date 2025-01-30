// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculation/CombatCalculationBase.h"

#include "GameplayUtilities.h"
#include "Attributes/RPGAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UCombatCalculationBase::UCombatCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, BlockChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, BlockValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, ParryChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGMeleeCombatAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, GlancingBlowChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, GlancingBlowValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalDefense, Target, false, true);
	/*DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, DamageBoost1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, DamageBoost2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, DamageBoost3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, DamageBoost4, Target, false, true);*/
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalValue, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, HitChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Penetration, Source, false, true);
}

void UCombatCalculationBase::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(CriticalChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HitChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Penetration, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(BlockChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BlockValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ParryChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EvadeChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlancingBlowChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlancingBlowValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDefense, ExecutionParams);
	
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	const float AbilityBonus = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(AbilityDamageBoostTag, true, 1);
	const float MinDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MinDamageTag, true, 0) * (1 + AbilityBonus);
	const float MaxDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MaxDamageTag, true, 0) * (1 + AbilityBonus);
	const float Damage1 = GetDamage(DamageTag, Spec);

	const float BaseDamage = FMath::RandRange(MinDamage, MaxDamage);
	const float Mitigation = GetMitigation(DamageTag, ExecutionParams, EvaluateParameters);
	const float DamageBoost = GetDamageBoost(DamageTag, Spec);
	float Damage = Damage1 + BaseDamage;
	
	Damage *= (DamageBoost / 1000);
	
	ECombatRollResult Result = UGameplayUtilities::DoCombatRoll(Damage, HitChance, Mitigation, BlockChance, BlockValue, ParryChance,
		EvadeChance, GlancingBlowChance, GlancingBlowChance, CriticalChance, CriticalDefense, CriticalValue,
		Penetration, 100.0f);

	float IncomingDamage = Damage;

	SourceComponent->ReportDamage(Result, IncomingDamage, Source, Target, DamageTag);
	TargetComponent->ReportDamage(Result, IncomingDamage, Source, Target, DamageTag);
	
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, IncomingDamage, OutExecutionOutput);	
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
	return FGameplayTag();
}

float UCombatCalculationBase::GetDamage(const FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const
{
	return Spec.GetSetByCallerMagnitude(DamageType, true, 0);	
}

float UCombatCalculationBase::GetDamageBoost(const FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const
{
	return 1;
}

float UCombatCalculationBase::GetMitigation(const FGameplayTag DamageType,
	const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	return 0;
}
