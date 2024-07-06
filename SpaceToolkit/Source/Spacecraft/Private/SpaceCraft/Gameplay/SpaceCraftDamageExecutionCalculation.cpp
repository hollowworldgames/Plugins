// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SpaceCraft/Gameplay/SpaceCraftDamageExecutionCalculation.h"

#include "UtilityStatics.h"
#include "WeaponAttributeSet.h"
#include "SpaceCraft/SpaceCraftActor.h"
#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"

USpaceCraftDamageExecutionCalculation::USpaceCraftDamageExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, HullHealth, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, HullPhysicalMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, HullEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, HullCriticalDefense, Target, false, true);

	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldPhysicalMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, ShieldCriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, FrontShieldHealth, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCraftAttributes, BackShieldHealth, Target, false, true);

	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponAccuracy, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponMinRange, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponMaxRange, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponMinDamage, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponMaxDamage, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponCriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UWeaponAttributeSet, WeaponCriticalDamage, Source, false, true);
}

FGameplayTag USpaceCraftDamageExecutionCalculation::GetComponentTargeted(const FGameplayEffectSpec& Spec) const
{
	FGameplayTagContainer ActorTags;
	FGameplayTagContainer SpecTags;
	
	Spec.GetContext().GetOwnedGameplayTags(ActorTags, SpecTags);
	//get damage type tag
	for(const FGameplayTag Tag : SpecTags.GetGameplayTagArray())
	{
		if(ComponentTags.HasTag(Tag))
		{
			return Tag;
		}
	}
	return FGameplayTag();
}

void USpaceCraftDamageExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(ASpaceCraftActor, ASpaceCraftActor, ExecutionParams);
	GET_EXECUTION_OWNERS(ASpaceCraftActor, ASpaceCraftActor);

	GET_EXECUTION_ATTRIBUTE(HullHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HullPhysicalMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HullEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HullCriticalDefense, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(ShieldPhysicalMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldCriticalDefense, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontShieldHealth, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackShieldHealth, ExecutionParams);
	
	GET_EXECUTION_ATTRIBUTE(WeaponAccuracy, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponMinRange, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponMaxRange, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponMinDamage, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponMaxDamage, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponCriticalChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(WeaponCriticalDamage, ExecutionParams);

	FGameplayTag DamageType = GetDamageType(Spec);

	double Range = FVector::Dist(Source->GetActorLocation(), Target->GetActorLocation());

	Range = FMath::Clamp(Range - WeaponMinRange / WeaponMaxRange - WeaponMinRange, 0, 1);
	WeaponMinDamage = Falloff.GetValueAtLevel(Range) * WeaponMinDamage;
	WeaponMaxDamage = Falloff.GetValueAtLevel(Range) * WeaponMaxDamage;
	
	if(DamageType.MatchesTag(PhysicalTag))
	{
		bool Critical = false;
		float Damage = 0;
		if(IsFrontHit(Spec) && FrontShieldHealth > 0)
		{
			Damage = CalculateDamage(WeaponMaxDamage, WeaponMinDamage, 1.0f, WeaponCriticalChance, WeaponCriticalDamage, ShieldCriticalDefense, Critical);
			Damage = CalculateMitigation(Damage, ShieldPhysicalMitigation, 0);
			float AppliedDamage = FMath::Min(FrontShieldHealth, Damage);
			Damage -= AppliedDamage;
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingFrontPhysicalDamage, OutExecutionOutput, AppliedDamage);
			
		}
		else if(BackShieldHealth > 0)
		{
			Damage = CalculateDamage(WeaponMaxDamage, WeaponMinDamage, 1.0f, WeaponCriticalChance, WeaponCriticalDamage, ShieldCriticalDefense, Critical);
			Damage = CalculateMitigation(Damage, ShieldPhysicalMitigation, 0);
			float AppliedDamage = FMath::Min(BackShieldHealth, Damage);
			Damage -= AppliedDamage;
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingBackPhysicalDamage, OutExecutionOutput, AppliedDamage);
		}

		//compute Hull Damage
		if(Damage > 0)
		{
			Damage = CalculateMitigation(Damage, HullPhysicalMitigation, 0);
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingHullPhysicalDamage, OutExecutionOutput, Damage);

			//Do Component damage here
			FGameplayTag Component = GetComponentTargeted(Spec);
			if(Component.IsValid())
			{
				if(Component.MatchesTag(ReactorTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingReactorDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(ShieldTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingShieldDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(BatteryTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingBatteryDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(EngineTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingEngineDamage, OutExecutionOutput, Damage);
				}
			}
		}
	}
	else
	{
		bool Critical = false;
		float Damage = 0;
		if(IsFrontHit(Spec) && FrontShieldHealth > 0)
		{
			Damage = CalculateDamage(WeaponMaxDamage, WeaponMinDamage, 1.0f, WeaponCriticalChance, WeaponCriticalDamage, ShieldCriticalDefense, Critical);
			Damage = CalculateMitigation(Damage, ShieldEnergyMitigation, 0);
			float AppliedDamage = FMath::Min(FrontShieldHealth, Damage);
			Damage -= AppliedDamage;
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingFrontEnergyDamage, OutExecutionOutput, AppliedDamage);
			
		}
		else if(BackShieldHealth > 0)
		{
			Damage = CalculateDamage(WeaponMaxDamage, WeaponMinDamage, 1.0f, WeaponCriticalChance, WeaponCriticalDamage, ShieldCriticalDefense, Critical);
			Damage = CalculateMitigation(Damage, ShieldEnergyMitigation, 0);
			float AppliedDamage = FMath::Min(BackShieldHealth, Damage);
			Damage -= AppliedDamage;
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingBackEnergyDamage, OutExecutionOutput, AppliedDamage);
		}

		//compute Hull Damage
		if(Damage > 0)
		{
			Damage = CalculateMitigation(Damage, HullEnergyMitigation, 0);
			WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingHullEnergyDamage, OutExecutionOutput, Damage);

			//Do Component damage here
			FGameplayTag Component = GetComponentTargeted(Spec);
			if(Component.IsValid())
			{
				if(Component.MatchesTag(ReactorTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingReactorDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(ShieldTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingShieldDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(BatteryTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingBatteryDamage, OutExecutionOutput, Damage);
				}
				else if(Component.MatchesTag(EngineTag))
				{
					WRITE_EXECUTION_ATTRIBUTE_LOCAL(USpaceCraftAttributes, IncomingEngineDamage, OutExecutionOutput, Damage);
				}
			}
		}
	}
}

FGameplayTag USpaceCraftDamageExecutionCalculation::GetDamageType(FGameplayEffectSpec Spec) const
{
	FGameplayTagContainer ActorTags;
	FGameplayTagContainer SpecTags;
	
	Spec.GetContext().GetOwnedGameplayTags(ActorTags, SpecTags);
	//get damage type tag
	for(const FGameplayTag Tag : SpecTags.GetGameplayTagArray())
	{
		if(Tag.MatchesTag(PhysicalTag))
		{
			return Tag;
		}
		if(Tag.MatchesTag(EnergyTag))
		{
			return Tag;
		}
	}
	return PhysicalTag;
}

float USpaceCraftDamageExecutionCalculation::CalculateDamage(float Max, float Min, float DamageAttribute,
												   float CriticalChance, float CriticalDamage, float CriticalDefense, bool& Critical) const
{
	float Damage = FMath::RandRange(Min + DamageAttribute, Max + DamageAttribute);
	
	if(UUtilityStatics::Roll1000(CriticalChance - CriticalDefense))
	{
		Damage += Damage * CriticalDamage;//critical hit
		Critical = true;
	}
	return Damage;
}

float USpaceCraftDamageExecutionCalculation::CalculateMitigation(float Damage, float Mitigation, float Penetration) const
{
	return Damage *  (1  - (FMath::Clamp(Mitigation - Penetration, 0.0f, 1000.0f) / 1000));
}

bool USpaceCraftDamageExecutionCalculation::IsFrontHit(FGameplayEffectSpec Spec) const
{
	return false;
}
