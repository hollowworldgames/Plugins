﻿// Fill out your copyright notice in the Description page of Project Settings.


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
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, IncomingDamage1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, IncomingDamage2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, IncomingDamage3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, IncomingDamage4, Target, false, true);
	
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
	GET_EXECUTION_ATTRIBUTE(IncomingDamage1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(IncomingDamage2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(IncomingDamage3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(IncomingDamage4, ExecutionParams);

	const float AbilityBonus = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(AbilityDamageBonusTag, true, 1);
	const float MinDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MinDamageTag, true, 0) * (1 + AbilityBonus);
	const float MaxDamage = ExecutionParams.GetOwningSpec().GetSetByCallerMagnitude(MaxDamageTag, true, 0) * (1 + AbilityBonus);

	float Damage = FMath::RandRange(MinDamage, MaxDamage);
	float Mitigation = 0;
	float DamageBoost = 1000;
	float & IncomingDamage = IncomingDamage1;
	
	FGameplayTag DamageTag = GetDamageTypeTag(Spec);
	if(DamageTag.MatchesTag(DamageTypeTag1))
	{
		Mitigation = Mitigation1;
		DamageBoost = DamageBoost1;
		IncomingDamage = IncomingDamage1;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag2))
	{
		Mitigation = Mitigation2;
		DamageBoost = DamageBoost2;
		IncomingDamage = IncomingDamage2;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag3))
	{
		Mitigation = Mitigation3;
		DamageBoost = DamageBoost3;
		IncomingDamage = IncomingDamage3;
	}
	else if(DamageTag.MatchesTag(DamageTypeTag4))
	{
		Mitigation = Mitigation4;
		DamageBoost = DamageBoost4;
		IncomingDamage = IncomingDamage4;
	}

	Damage *= (DamageBoost / 1000);
	
	ECombatRollResult Result = UGameplayUtilities::DoCombatRoll(Damage, Accuracy, Mitigation, BlockChance, BlockValue, ParryChance,
		EvadeChance, GlancingBlowChance, CriticalChance, CriticalDefense, CriticalValue, Penetration);

	SourceComponent->ReportDamage(Result, Damage, Source, Target, DamageTag);
	TargetComponent->ReportDamage(Result, Damage, Source, Target, DamageTag);
	
	if(DamageTag.MatchesTag(DamageTypeTag1))
	{
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, IncomingDamage1, OutExecutionOutput, IncomingDamage);	
	}
	else if(DamageTag.MatchesTag(DamageTypeTag2))
	{
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, IncomingDamage2, OutExecutionOutput, IncomingDamage);	
	}
	else if(DamageTag.MatchesTag(DamageTypeTag3))
	{
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, IncomingDamage3, OutExecutionOutput, IncomingDamage);	
	}
	else if(DamageTag.MatchesTag(DamageTypeTag4))
	{
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, IncomingDamage4, OutExecutionOutput, IncomingDamage);	
	}
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
