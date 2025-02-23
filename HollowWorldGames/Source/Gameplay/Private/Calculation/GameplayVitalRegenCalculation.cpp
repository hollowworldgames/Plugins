// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculation/GameplayVitalRegenCalculation.h"

#include "AttributeMacros.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

UGameplayVitalRegenCalculation::UGameplayVitalRegenCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Energy, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Mana, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, HealthRegen, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, EnergyRegen, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, ManaRegen, Source, false, true);
}

void UGameplayVitalRegenCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Energy, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mana, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HealthRegen, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EnergyRegen, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ManaRegen, ExecutionParams);

	float HealthCombatMultiplier = 1.0f;
	float EnergyCombatMultiplier = 1.0f;
	float ManaCombatMultiplier = 1.0f;

	if (SourceComponent->HasTag(CombatTag))
	{
		HealthCombatMultiplier = HealthInCombatModifier;
		EnergyCombatMultiplier = EnergyInCombatModifier;
		ManaCombatMultiplier = ManaInCombatModifier;
	}
	
	Health += Health * (HealthRegen / 1000.0f) * Spec.Period * HealthCombatMultiplier;
	Energy += Energy * (EnergyRegen / 1000.0f) * Spec.Period * EnergyCombatMultiplier;
	Mana += Mana * (ManaRegen / 1000.0f) * Spec.Period * ManaCombatMultiplier;
	
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, Health, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, Energy, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, Mana, OutExecutionOutput);
}
