// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "CombatCalculationBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UCombatCalculationBase : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UCombatCalculationBase();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	FGameplayTag GetDamageTypeTag(const FGameplayEffectSpec& Spec) const;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Accuracy)
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation4);
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
	DECLARE_ATTRIBUTE_CAPTUREDEF2(IncomingDamage1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(IncomingDamage2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(IncomingDamage3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(IncomingDamage4);

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
