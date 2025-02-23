// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GameplayVitalRegenCalculation.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayVitalRegenCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UGameplayVitalRegenCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Energy);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Mana);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(HealthRegen);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EnergyRegen);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(ManaRegen);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	float HealthInCombatModifier = 0.1f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	float EnergyInCombatModifier = 0.1f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	float ManaInCombatModifier = 0.1f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	FGameplayTag CombatTag;
};
