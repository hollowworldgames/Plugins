// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DamageExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAMEPLAY_API UDamageExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UDamageExecutionCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected:
	bool IsHit(float HitChance, float EvadeChance) const;
	bool IsCriticalHit(float CriticalHit, float CriticalDefense) const;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HitChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EvadeChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlanceChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlanceValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(KineticMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalDamage);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalDefense);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldFaces);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontKineticMitigation);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackKineticMitigation);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightKineticMitigation);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftEnergyMitigation);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftKineticMitigation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Attributes)
	FScalableFloat DamageFalloff;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Tags)
	FGameplayTag ComponentTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Chances)
	float ComponentHitChance = 25;
};
