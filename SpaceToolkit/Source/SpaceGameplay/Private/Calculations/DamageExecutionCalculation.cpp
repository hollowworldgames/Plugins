// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/DamageExecutionCalculation.h"

#include "AttributeMacros.h"
#include "UtilityStatics.h"
#include "VectorTypes.h"
#include "Attributes/CombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Interfaces/ComponentContainerInterface.h"
#include "Interfaces/DamageReportInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxDamageTag, "Combat.Parameters.MaxDamage", "Max Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MinDamageTag,"Combat.Parameters.MinDamage","Min Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxRangeTag,"Combat.Parameters.MaxRange","Max Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MinRangeTag,"Combat.Parameters.MinRange","Min Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(KineticDamageTag,"Combat.Parameters.KineticDamage","Kinetic Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnergyDamageTag,"Combat.Parameters.EnergyDamage","Energy Damage");

UDamageExecutionCalculation::UDamageExecutionCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, HitChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, CriticalDamage, Source, false, true);

	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, GlanceChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, GlanceValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, KineticMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, EnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, FrontShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, FrontKineticMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, FrontEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, BackShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, BackKineticMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, BackEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, RightShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, RightKineticMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, RightEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, LeftShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, LeftKineticMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, LeftEnergyMitigation, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UCombatAttributeSet, ShieldFaces, Target, false, true);
}

void UDamageExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	INITIALIZE_EXECUTION_CALC2(AActor, AActor, ExecutionParams);
	GET_EXECUTION_OWNERS(AActor, AActor);

	GET_EXECUTION_ATTRIBUTE(Health, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(HitChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDamage, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EvadeChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlanceChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlanceValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDefense, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(KineticMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontKineticMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackKineticMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightKineticMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftKineticMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftEnergyMitigation, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldFaces, ExecutionParams);

	EDamageReportType Type = EDamageReportType::Miss;

	if (!IsHit(HitChance, EvadeChance))
	{
		return;
	}
	Type = EDamageReportType::NormalHit;
	int HitFace = 0;

	float MaxDamage = Spec.GetSetByCallerMagnitude(MaxDamageTag);
	float MinDamage = Spec.GetSetByCallerMagnitude(MinDamageTag);
	float MaxRange = Spec.GetSetByCallerMagnitude(MaxRangeTag);
	float MinRange = Spec.GetSetByCallerMagnitude(MinRangeTag);

	float Damage = FMath::RandRange(MinDamage, MaxDamage);

	
	
	if (UUtilityStatics::Roll1000(GlanceChance))
	{
		Damage *= GlanceValue;
		Type = EDamageReportType::GlancingHit;
	}
	else if (IsCriticalHit(CriticalChance, CriticalDefense))
	{
		Damage *= CriticalDamage;
		Type = EDamageReportType::CriticalHit;
	}
	
	
	float KineticDamage = 0;
    float EnergyDamage = 0;
	FGameplayTag TargetedComponent;
	if (EvaluateParameters.SourceTags)
	{
		for (const FGameplayTag Tag : *EvaluateParameters.SourceTags)
		{
			if (Tag.MatchesTag(ComponentTag))
			{
				TargetedComponent = Tag;
			}
		}
	}
	const FHitResult * Result = Spec.GetEffectContext().GetHitResult();
	if(ensure(Result))
	{
		double Range = FMath::Clamp((FVector::Distance(Target->GetActorLocation(), Result->Location) - MinRange) / (MinRange - MaxRange), 0.0, 1.0);
		Damage *= DamageFalloff.GetValueAtLevel(Range);
		KineticDamage = Damage * Spec.GetSetByCallerMagnitude(KineticDamageTag);
		EnergyDamage = Damage * Spec.GetSetByCallerMagnitude(EnergyDamageTag);
		if (ShieldFaces > 0)
		{
			if (ShieldFaces < 4)
			{
				float forward = Target->GetActorForwardVector().Dot(UUtilityStatics::GetVectorTo(Source->GetActorLocation(),Result->Location));
				if (forward < 0)
				{
					HitFace = 1;
				}
			}
			else
			{
				float forward = Target->GetActorForwardVector().Dot(UUtilityStatics::GetVectorTo(Source->GetActorLocation(),Result->Location));
				float right = Target->GetActorRightVector().Dot(UUtilityStatics::GetVectorTo(Source->GetActorLocation(),Result->Location));
				if (FMath::Abs(forward) < 0.5f)
				{
					if (right < 0)
					{
						HitFace = 3;
					}
					else
					{
						HitFace = 2;
					}
				}
				else
				{
					if (forward < 0)
					{
						HitFace = 1;
					}
				}
			}
		}
	}

	
	switch (HitFace)
	{
	case 0 :
		{
			if (FrontShield > 0)
			{
				KineticDamage *= (1 - FrontKineticMitigation);
				EnergyDamage *= (1 - FrontEnergyMitigation);
				float damageApply = FMath::Min(FrontShield, KineticDamage);
				FrontShield -= damageApply;
				KineticDamage -= damageApply;
				damageApply = FMath::Min(FrontShield, EnergyDamage);
				FrontShield -= damageApply;
				EnergyDamage -= damageApply;
				WRITE_EXECUTION_ATTRIBUTE(UCombatAttributeSet, FrontShield, OutExecutionOutput);
			}
			break;
		}
	case 1:
		{
			if (BackShield > 0)
			{
				KineticDamage *= (1 - FrontKineticMitigation);
				EnergyDamage *= (1 - FrontEnergyMitigation);
				float damageApply = FMath::Min(BackShield, KineticDamage);
				BackShield -= damageApply;
				KineticDamage -= damageApply;
				damageApply = FMath::Min(BackShield, EnergyDamage);
				BackShield -= damageApply;
				EnergyDamage -= damageApply;
				WRITE_EXECUTION_ATTRIBUTE(UCombatAttributeSet, BackShield, OutExecutionOutput);
			}
			break;
		}
	case 2:
		{
			if (RightShield > 0)
			{
				KineticDamage *= (1 - FrontKineticMitigation);
				EnergyDamage *= (1 - FrontEnergyMitigation);
				float damageApply = FMath::Min(RightShield, KineticDamage);
				RightShield -= damageApply;
				KineticDamage -= damageApply;
				damageApply = FMath::Min(RightShield, EnergyDamage);
				RightShield -= damageApply;
				EnergyDamage -= damageApply;
				WRITE_EXECUTION_ATTRIBUTE(UCombatAttributeSet, RightShield, OutExecutionOutput);
			}
			break;
		}
	case 3:
		{
			if (LeftShield > 0)
			{
				KineticDamage *= (1 - FrontKineticMitigation);
				EnergyDamage *= (1 - FrontEnergyMitigation);
				float damageApply = FMath::Min(LeftShield, KineticDamage);
				LeftShield -= damageApply;
				KineticDamage -= damageApply;
				damageApply = FMath::Min(LeftShield, EnergyDamage);
				LeftShield -= damageApply;
				EnergyDamage -= damageApply;
				WRITE_EXECUTION_ATTRIBUTE(UCombatAttributeSet, LeftShield, OutExecutionOutput);
			}
			break;
		}
	default: ensure(false);
	}

	if (KineticDamage + EnergyDamage > 0) //not all absorbed by shield
	{
		KineticDamage *= 1 - KineticMitigation;
		EnergyDamage *= 1 - EnergyMitigation;
		Damage = KineticDamage + EnergyDamage;
		//Apply Hull Damage
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(UVitalAttributeSet, IncomingDamage, OutExecutionOutput, Damage);
		//Apply Component Damage
		if(TScriptInterface<IComponentContainerInterface> Container = TObjectPtr<AActor>(const_cast<AActor*>(Target)))
		{
			if(!TargetedComponent.IsValid() && UUtilityStatics::Roll100(ComponentHitChance))
			{
				TArray<FGameplayTag> Components = Container->GetComponents();
				TargetedComponent = UUtilityStatics::GetRandomItem(Components);
			}
			Container->ApplyDamageToComponent(TargetedComponent, Damage, Source);
			if (TScriptInterface<IDamageReportInterface> Reporter = TObjectPtr<AActor>(const_cast<AActor*>(Target)))
			{
				Reporter->ReportComponentDamage(Source, EnergyDamage, KineticDamage, TargetedComponent, Type);
			}
		}
		if (TScriptInterface<IDamageReportInterface> Reporter = TObjectPtr<AActor>(const_cast<AActor*>(Target)))
		{
			Reporter->ReportDamage(Source, EnergyDamage, KineticDamage, Type);
		}
	}
	else
	{
		//report shield hit to target
		if (TScriptInterface<IDamageReportInterface> Reporter = TObjectPtr<AActor>(const_cast<AActor*>(Target)))
		{
			Reporter->ReportDamage(Source, EnergyDamage, KineticDamage, HitFace, Type);
		}
	}
}

bool UDamageExecutionCalculation::IsHit(float HitChance, float EvadeChance) const
{
	const float Chance = HitChance - EvadeChance;
	return UUtilityStatics::Roll1000(Chance);
}

bool UDamageExecutionCalculation::IsCriticalHit(float CriticalHit, float CriticalDefense) const
{
	const float Chance = CriticalHit - CriticalDefense;
	return UUtilityStatics::Roll1000(Chance);
}
