// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Calculations/DamageExecutionCalculation.h"

#include "AttributeMacros.h"
#include "UtilityStatics.h"
#include "VectorTypes.h"
#include "Attributes/SpaceCombatAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
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
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, HitChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalChance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalValue, Source, false, true);

	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Health, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, EvadeChance, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, GlancingBlowChance, Target, false, true);
	//DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, GlancingBlowValue, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, CriticalDefense, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Mitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontMitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontMitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontMitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, FrontMitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackMitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackMitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackMitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, BackMitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightMitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightMitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightMitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, RightMitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftShield, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftMitigation1, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftMitigation2, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftMitigation3, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, LeftMitigation4, Target, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(USpaceCombatAttributeSet, ShieldFaces, Target, false, true);
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
	GET_EXECUTION_ATTRIBUTE(CriticalValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(EvadeChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlancingBlowChance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(GlancingBlockValue, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(CriticalDefense, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Mitigation4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontMitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontMitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontMitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(FrontMitigation4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackMitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackMitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackMitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(BackMitigation4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightMitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightMitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightMitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(RightMitigation4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftShield, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftMitigation1, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftMitigation2, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftMitigation3, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(LeftMitigation4, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(ShieldFaces, ExecutionParams);

	float MaxDamage = Spec.GetSetByCallerMagnitude(MaxDamageTag);
	float MinDamage = Spec.GetSetByCallerMagnitude(MinDamageTag);
	float MaxRange = Spec.GetSetByCallerMagnitude(MaxRangeTag);
	float MinRange = Spec.GetSetByCallerMagnitude(MinRangeTag);

	float BaseDamage = FMath::RandRange(MinDamage, MaxDamage);
	
	
	int HitFace = 0;

	
	float KineticDamage = Spec.GetSetByCallerMagnitude(KineticDamageTag);
	float EnergyDamage = Spec.GetSetByCallerMagnitude(EnergyDamageTag);
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
		BaseDamage *= DamageFalloff.GetValueAtLevel(Range);
		
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
	FVector4f Damage(KineticDamage * BaseDamage, EnergyDamage * BaseDamage);
	
	ECombatRollResult RollResult = UGameplayUtilities::DoCombatRoll(Damage, HitChance, FVector4f::Zero(),
		0, 0, 0, EvadeChance, GlancingBlowChance, GlancingBlowChance,
		CriticalChance, CriticalDefense, CriticalValue, 0, 0);
	if (RollResult == ECombatRollResult::Miss)
	{
		return;
	}
	
	switch (HitFace)
	{
	case 0 :
		{
			if (FrontShield > 0)
			{
				Damage = UGameplayUtilities::ApplyMitigation(Damage, FrontMitigation1, FrontMitigation2,
					FrontMitigation3, FrontMitigation4);
				ApplyToShield(FrontShield, Damage);
				WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, FrontShield, OutExecutionOutput);
			}
			break;
		}
	case 1:
		{
			if (BackShield > 0)
			{
				Damage = UGameplayUtilities::ApplyMitigation(Damage, BackMitigation1, BackMitigation2,
					BackMitigation3, BackMitigation4);
				ApplyToShield(FrontShield, Damage);
				WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, BackShield, OutExecutionOutput);
			}
			break;
		}
	case 2:
		{
			if (RightShield > 0)
			{
				Damage = UGameplayUtilities::ApplyMitigation(Damage, RightMitigation1, RightMitigation2,
					RightMitigation3, RightMitigation4);
				ApplyToShield(RightShield, Damage);
				WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, RightShield, OutExecutionOutput);
			}
			break;
		}
	case 3:
		{
			if (LeftShield > 0)
			{
				Damage = UGameplayUtilities::ApplyMitigation(Damage, LeftMitigation1, LeftMitigation2,
					LeftMitigation3, LeftMitigation4);
				ApplyToShield(LeftShield, Damage);
				WRITE_EXECUTION_ATTRIBUTE(USpaceCombatAttributeSet, LeftShield, OutExecutionOutput);
			}
			break;
		}
	default: ensure(false);
	}
	FGameplayTag MainDamageType;
	if (KineticDamage + EnergyDamage > 0) //not all absorbed by shield
	{
		Damage = UGameplayUtilities::ApplyMitigation(Damage, Mitigation1, Mitigation2,
					Mitigation3, Mitigation4);
		//Apply Hull Damage
		float DamageApply = Damage.X + Damage.Y+Damage.Z+Damage.W;
		WRITE_EXECUTION_ATTRIBUTE_LOCAL(UVitalAttributeSet, IncomingDamage, OutExecutionOutput, DamageApply);
		//Apply Component Damage
		if(TScriptInterface<IComponentContainerInterface> Container = TObjectPtr<AActor>(const_cast<AActor*>(Target)))
		{
			if(!TargetedComponent.IsValid() && UUtilityStatics::Roll100(ComponentHitChance))
			{
				TArray<FGameplayTag> Components = Container->GetComponentTags();
				TargetedComponent = UUtilityStatics::GetRandomItem(Components);
			}
			Container->ApplyDamageToComponent(TargetedComponent, DamageApply, Source);
		}
		TargetComponent->ReportDamage(RollResult, DamageApply, SourceOwner, Target,  MainDamageType);
	}
	else
	{
		//report shield hit to target
		TargetComponent->ReportDamage(RollResult, Damage.X + Damage.Y + Damage.Z + Damage.W, SourceOwner, Target,  MainDamageType);
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

void UDamageExecutionCalculation::ApplyToShield(float& Shield, FVector4f& Damage) const
{
	for (int x = 0; x < Damage.Size(); x++)
	{
		float damageApply = FMath::Min(Shield, Damage[x]);
		Shield -= damageApply;
		Damage[x] -= damageApply;
	}
}
