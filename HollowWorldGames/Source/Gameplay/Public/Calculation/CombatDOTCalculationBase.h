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
	FGameplayTag GetDamageTypeTag(const FGameplayEffectSpec& Spec) const;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HitChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Resistance1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Resistance2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Resistance3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Resistance4);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(DamageBoost1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(DamageBoost2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(DamageBoost3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(DamageBoost4);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BlockChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BlockValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ParryChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EvadeChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlancingBlowChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalDefense);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Penetration);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag DamageTypeTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag DamageTypeTag1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag DamageTypeTag2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag DamageTypeTag3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag DamageTypeTag4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag MinDamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag MaxDamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag AbilityDamageBonusTag;
};
