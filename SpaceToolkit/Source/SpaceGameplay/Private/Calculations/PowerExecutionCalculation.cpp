// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/PowerExecutionCalculation.h"

#include "Attributes/ReactorAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UPowerExecutionCalculation::UPowerExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UReactorAttributeSet, MaxPowerOutput, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UReactorAttributeSet, FuelAvailable, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UReactorAttributeSet, FuelNeeded, Source, false, true);
}

void UPowerExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FuelAvailable, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FuelNeeded, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxPowerOutput, ExecutionParams);
	
	float PowerOutput = 0;
	if (EvaluateParameters.SourceTags->HasTagExact(ReactorOnTag))
	{
		PowerOutput = MaxPowerOutput * (FuelAvailable / FuelNeeded) * Efficiency.GetValueAtLevel(Health/ MaxHealth);
	}
	WRITE_EXECUTION_ATTRIBUTE(UReactorAttributeSet, PowerOutput, OutExecutionOutput);
}
