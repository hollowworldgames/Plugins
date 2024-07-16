// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Gameplay/SpaceCraftExecutionCalculation.h"

#include "Components/GameplayAbilitySystemComponent.h"
#include "SpaceCraft/SpaceCraftActor.h"
#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"

USpaceCraftExecutionCalculation::USpaceCraftExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ReactorHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ReactorBoost, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ReactorLevel, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BatteryHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BatteryBoost, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BatteryLevel, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BatteryPower, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, MaxBatteryPower, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldOn, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldLevel, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldBoost, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, FrontShieldHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, MaxFrontShieldHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BackShieldHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, MaxBackShieldHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, WeaponDistribution, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldDistribution, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, EngineDistribution, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, EngineHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, MaxEngineHealth, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, EngineOn, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, EngineLevel, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, EngineBoost, Source, false, true);
}

void USpaceCraftExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC(ASpaceCraftActor, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(ReactorLevel, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ReactorBoost, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ReactorHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxReactorHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BatteryLevel, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BatteryBoost, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BatteryHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxBatteryHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BatteryPower, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxBatteryPower, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(WeaponDistribution, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EngineDistribution, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldDistribution, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(ShieldOn, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldLevel, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldBoost, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxFrontShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxBackShieldHealth, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(EngineOn, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EngineHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(MaxEngineHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EngineLevel, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EngineBoost, ExecutionParams);
	//Do Power Generation

	float PowerGenerated = ReactorOutput.GetValueAtLevel(ReactorLevel) * ReactorBoost
		* DamageEfficacy.GetValueAtLevel((MaxReactorHealth> 0) ? ReactorHealth/MaxReactorHealth : 0);
	
	float WeaponPower = PowerGenerated * WeaponDistribution;
	float EnginePower = PowerGenerated * EngineDistribution;
	float ShieldPower = PowerGenerated * ShieldDistribution * ShieldOn;

	float BatteryCharge = PowerGenerated - WeaponPower + EnginePower + ShieldPower
		* DamageEfficacy.GetValueAtLevel((MaxBatteryHealth> 0) ? BatteryHealth/MaxBatteryHealth : 0);;
	
	BatteryPower = FMath::Clamp(BatteryPower + BatteryCharge + Spec.Period, 0, MaxBatteryPower);

	//Do Shield Recharge

	if(ShieldLevel > 0)
	{
		float ShieldHitPoints = ShieldPower * ShieldRecharge.GetValueAtLevel(ShieldLevel) * ShieldBoost
			* DamageEfficacy.GetValueAtLevel((MaxShieldHealth> 0) ? ShieldHealth/MaxShieldHealth : 0) * Spec.Duration;

		if(FrontShieldHealth < MaxFrontShieldHealth && BackShieldHealth < MaxBackShieldHealth)
		{
			ShieldHitPoints /= 2.0;
			FrontShieldHealth = FMath::Clamp(FrontShieldHealth + ShieldHitPoints, 0, MaxFrontShieldHealth);
			BackShieldHealth = FMath::Clamp(BackShieldHealth + ShieldHitPoints, 0, MaxBackShieldHealth);
		}
		else if(FrontShieldHealth < MaxFrontShieldHealth)
		{
			FrontShieldHealth = FMath::Clamp(FrontShieldHealth + ShieldHitPoints, 0, MaxFrontShieldHealth);
		}
		else if(BackShieldHealth < MaxBackShieldHealth)
		{
			BackShieldHealth = FMath::Clamp(BackShieldHealth + ShieldHitPoints, 0, MaxBackShieldHealth);
		}
	}
	else
	{
		FrontShieldHealth = 0;
		BackShieldHealth = 0;
	}
	float EngineThrust = 0;
	if(EngineLevel > 0)
	{
		EngineThrust = EngineOutput.GetValueAtLevel(EngineLevel) * EngineBoost
		* DamageEfficacy.GetValueAtLevel((MaxEngineHealth > 0) ? EngineHealth / MaxEngineHealth : 0) * EngineOn;
	}
	
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, PowerGenerated, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, WeaponPower, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, EnginePower, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, ShieldPower, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, BatteryPower, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, FrontShieldHealth, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, BackShieldHealth, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(USpaceCraftAttributes, EngineThrust, OutExecutionOutput);
}
