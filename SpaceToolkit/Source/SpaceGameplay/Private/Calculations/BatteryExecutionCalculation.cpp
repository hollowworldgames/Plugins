// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/BatteryExecutionCalculation.h"

#include "Attributes/BatteryAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UBatteryExecutionCalculation::UBatteryExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UBatteryAttributeSet, StoredPower, Source, false, true);
}

void UBatteryExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(StoredPower, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BatteryPower, ExecutionParams);

	if (EvaluateParameters.SourceTags->HasTagExact(BatteryOnTag))
	{
		StoredPower += BatteryPower * ExecutionParams.GetOwningSpec().Period;
	}
	WRITE_EXECUTION_ATTRIBUTE(UBatteryAttributeSet, BatteryPower, OutExecutionOutput);
}
