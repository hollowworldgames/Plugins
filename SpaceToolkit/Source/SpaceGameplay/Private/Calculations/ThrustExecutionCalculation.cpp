// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/ThrustExecutionCalculation.h"

#include "Attributes/EngineAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UThrustExecutionCalculation::UThrustExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UEngineAttributeSet, EnginePower, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UEngineAttributeSet, PowerToThrust, Source, false, true);
}

void UThrustExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EnginePower, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(PowerToThrust, ExecutionParams);

	float EngineThrust = 0.0f;
	
	if (EvaluateParameters.SourceTags->HasTagExact(EngineOnTag) && MaxHealth > 0.0f && Health > 0.0f)
	{
		EngineThrust = PowerToThrust * EnginePower * Efficiency.GetValueAtLevel(Health/MaxHealth);
	}

	WRITE_EXECUTION_ATTRIBUTE(UEngineAttributeSet, EngineThrust, OutExecutionOutput);
}
