// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/ShieldExecutionCalculation.h"

#include "Attributes/SpaceCombatAttributeSet.h"
#include "Attributes/Equipment/ShieldAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"

UShieldExecutionCalculation::UShieldExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, MaxHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, PowerToHitPoints, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, MaxFrontShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, MaxBackShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, MaxRightShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, MaxLeftShield, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UShieldAttributeSet, ShieldPower, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, ShieldFaces, Source, false, true);
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
	GET_EXECUTION_ATTRIBUTE(FrontShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxFrontShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxBackShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxRightShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxLeftShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldPower, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldFaces, ExecutionParams);

	if (EvaluateParameters.SourceTags->HasTagExact(ShieldOnTag))
	{
		
		float HitPointNeeded = (MaxFrontShield - FrontShield) + (MaxBackShield - BackShield) + (MaxRightShield - RightShield) + (MaxLeftShield - LeftShield);
		if (HitPointNeeded > 0)
		{
			float HitPointAvailable = PowerToHitPoints * ShieldPower * Efficiency.GetValueAtLevel(Health/ MaxHealth); 

			switch (static_cast<int>(ShieldFaces))
			{
			case 1:
				{
					if (FrontShield < MaxFrontShield)
					{
						float HitPointToHeal = FMath::Min(MaxFrontShield - FrontShield, HitPointAvailable);
						FrontShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, FrontShield, OutExecutionOutput);
					}
					break;
				}
			case 2 :
				{
					if (FrontShield < MaxFrontShield)
					{
						float HitPointToHeal = FMath::Min(MaxFrontShield - FrontShield, HitPointAvailable);
						HitPointAvailable -= HitPointToHeal;
						FrontShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, FrontShield, OutExecutionOutput);
					}

					if (BackShield < MaxBackShield)
					{
						float HitPointToHeal = FMath::Min(MaxBackShield - BackShield, HitPointAvailable);
						BackShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, BackShield, OutExecutionOutput);
					}
					break;
				}
			case 4 :
				{
					if (FrontShield < MaxFrontShield)
					{
						float HitPointToHeal = FMath::Min(MaxFrontShield - FrontShield, HitPointAvailable);
						HitPointAvailable -= HitPointToHeal;
						FrontShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, FrontShield, OutExecutionOutput);
					}

					if (BackShield < MaxBackShield && HitPointAvailable > 0)
					{
						float HitPointToHeal = FMath::Min(MaxBackShield - BackShield, HitPointAvailable);
						HitPointAvailable -= HitPointToHeal;
						BackShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, BackShield, OutExecutionOutput);
					}

					if (RightShield < MaxRightShield && HitPointAvailable > 0)
					{
						float HitPointToHeal = FMath::Min(MaxRightShield - RightShield, HitPointAvailable);
						HitPointAvailable -= HitPointToHeal;
						RightShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, RightShield, OutExecutionOutput);
					}

					if (LeftShield < MaxLeftShield && HitPointAvailable > 0)
					{
						float HitPointToHeal = FMath::Min(MaxLeftShield - LeftShield, HitPointAvailable);
						LeftShield += HitPointToHeal;
						WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, LeftShield, OutExecutionOutput);
					}
					break;
				}
			default:
				{
					ensure(false);
				}
			}
		}
	}
}
