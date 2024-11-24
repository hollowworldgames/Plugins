// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/ShieldExecutionCalculation.h"

#include "Attributes/ShieldAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UShieldExecutionCalculation::UShieldExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, PowerToHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldFrontHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldMaxFrontHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldBackHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldMaxBackHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldPower, Source, false, true);
}

void UShieldExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(PowerToHitPoints, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldFrontHitPoints, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldMaxFrontHitPoints, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldBackHitPoints, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldMaxBackHitPoints, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldPower, ExecutionParams);

	if (EvaluateParameters.SourceTags->HasTagExact(ShieldOnTag))
	{
		float HitPointNeeded = (ShieldMaxFrontHitPoints - ShieldFrontHitPoints) + (ShieldMaxBackHitPoints - ShieldBackHitPoints);
		if (HitPointNeeded > 0)
		{
			float HitPointAvailable = PowerToHitPoints * ShieldPower * Efficiency.GetValueAtLevel(Health/ MaxHealth); 
			
			if (ShieldFrontHitPoints < ShieldMaxFrontHitPoints)
			{
				float HitPointToHeal = FMath::Min(ShieldMaxFrontHitPoints - ShieldFrontHitPoints, HitPointAvailable);
				HitPointAvailable -= HitPointToHeal;
				ShieldFrontHitPoints += HitPointToHeal;
				WRITE_EXECUTION_ATTRIBUTE(UShieldAttributeSet, ShieldFrontHitPoints, OutExecutionOutput);
			}
			
			if (ShieldBackHitPoints < ShieldMaxBackHitPoints)
			{
				float HitPointToHeal = FMath::Min(ShieldMaxBackHitPoints - ShieldBackHitPoints, HitPointAvailable);
				ShieldBackHitPoints += HitPointToHeal;
				WRITE_EXECUTION_ATTRIBUTE(UShieldAttributeSet, ShieldBackHitPoints, OutExecutionOutput);
			}
		}
	}
}
