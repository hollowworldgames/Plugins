// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "CombatDOTCalculationBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UCombatDOTCalculationBase : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UCombatDOTCalculationBase();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected :
	FGameplayTag GetDamageTypeTag(const FGameplayEffectSpec& Spec) const;
	virtual float GetDamage(FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const;
	virtual float GetResistance(FGameplayTag DamageTag, const FGameplayEffectCustomExecutionParameters& Spec,
		const FAggregatorEvaluateParameters& EvaluateParameters) const;
	virtual float GetDamageBoost(FGameplayTag DamageType, const FGameplayEffectSpec& Spec) const;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HitChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BlockChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BlockValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ParryChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EvadeChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlancingBlowChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalDefense);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Penetration);
};


