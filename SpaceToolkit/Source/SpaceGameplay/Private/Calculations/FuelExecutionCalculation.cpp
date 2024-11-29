// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/FuelExecutionCalculation.h"

#include "Attributes/Equipment/FuelAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UFuelExecutionCalculation::UFuelExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UFuelAttributeSet, Fuel, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UReactorAttributeSet, FuelNeeded, Target, false, true);
}

void UFuelExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Fuel, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FuelNeeded, ExecutionParams);

	float FuelAvailable = 0;
	if (EvaluateParameters.SourceTags->HasTagExact(FuelOnTag))
	{
		if (Fuel > FuelNeeded * ExecutionParams.GetOwningSpec().Period)
		{
			Fuel -= FuelNeeded * ExecutionParams.GetOwningSpec().Period;
			FuelAvailable = FuelNeeded;
		}
	}
	WRITE_EXECUTION_ATTRIBUTE(UReactorAttributeSet, FuelAvailable, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UFuelAttributeSet, Fuel, OutExecutionOutput);
}
