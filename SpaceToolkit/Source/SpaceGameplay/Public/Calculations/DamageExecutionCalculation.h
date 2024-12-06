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
	void ApplyToShield(float& Shield, FVector4f& Damage) const;
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HitChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EvadeChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlancingBlowChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(GlancingBlockValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mitigation4);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalChance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalValue);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(CriticalDefense);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ShieldFaces);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontMitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontMitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontMitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(FrontMitigation4);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackMitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackMitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackMitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(BackMitigation4);

	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightMitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightMitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightMitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(RightMitigation4);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftShield);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftMitigation1);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftMitigation2);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftMitigation3);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(LeftMitigation4);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Attributes)
	FScalableFloat DamageFalloff;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Tags)
	FGameplayTag ComponentTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Chances)
	float ComponentHitChance = 25;
};
