// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "SpaceCraftDamageExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACECRAFT_API USpaceCraftDamageExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	USpaceCraftDamageExecutionCalculation();
	FGameplayTag GetComponentTargeted(const FGameplayEffectSpec& Spec) const;
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	FGameplayTag GetDamageType(FGameplayEffectSpec Spec) const;
	float CalculateDamage(float Max, float Min, float DamageAttribute, float CriticalChance, float CriticalDamage,
	                      float CriticalDefense, bool& Critical) const;
	float CalculateMitigation(float Damage, float Mitigation, float Penetration) const;
protected:

	bool IsFrontHit(FGameplayEffectSpec Spec) const;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HullHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HullPhysicalMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HullEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HullCriticalDefense);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackShieldHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldPhysicalMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldCriticalDefense);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponMinRange);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponMaxRange);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponMinDamage);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponMaxDamage);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponCriticalChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponCriticalDamage);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(WeaponAccuracy);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FScalableFloat Falloff;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag PhysicalTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag EnergyTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Tags)
	FGameplayTagContainer ComponentTags;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Tags)
	FGameplayTag ReactorTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Tags)
	FGameplayTag BatteryTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Tags)
	FGameplayTag ShieldTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Tags)
	FGameplayTag EngineTag;
};
