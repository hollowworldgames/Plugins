// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayUtilities.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Weapons/GameplayWeaponTags.h"


float UGameplayUtilities::ParryValue = 0.4f;

ECombatRollResult UGameplayUtilities::DoCombatRoll(float& Damage, const float Accuracy, const float Mitigation, const float BlockChance,
	const float BlockValue, const float ParryChance, const float EvadeChance, const float GlanceChance, const float GlanceValue, const float CriticalChance,
	const float CriticalDefense, const float CriticalValue, const float PenetrationChance, float PenetrationValue)
{
	if(UUtilityStatics::Roll1000(Accuracy))
	{
		if(BlockChance > 0)
		{
			if(UUtilityStatics::Roll1000(BlockChance))
			{
				Damage = Damage * (BlockValue / 1000);
				Damage = ApplyMitigation(Damage, Mitigation);
				return ECombatRollResult::Block;		
			}
		}
		if(ParryChance > 0)
		{
			if(UUtilityStatics::Roll1000(ParryChance))
			{
				Damage = Damage * ParryValue;
				Damage = ApplyMitigation(Damage, Mitigation);
				return ECombatRollResult::Parry;
			}
		}
		if(EvadeChance > 0)
		{
			if(UUtilityStatics::Roll1000(EvadeChance))
			{
				Damage = 0;
				return ECombatRollResult::Evade;
			}
		}
		if(GlanceChance > 0)
		{
			if(UUtilityStatics::Roll1000(GlanceChance))
			{
				Damage = Damage * ((1000 - GlanceValue)/1000);
				Damage = ApplyMitigation(Damage, Mitigation);
				return ECombatRollResult::Glance;
			}
		}
		//do crit here
		if(ApplyCriticalHit(Damage, CriticalChance, CriticalDefense, CriticalValue))
		{
			//critical Hit
			Damage = ApplyMitigation(Damage, Mitigation);
			return ECombatRollResult::CriticalHit;
		}
		if(!UUtilityStatics::Roll1000(PenetrationChance))
		{
			Damage = ApplyMitigation(Damage, Mitigation);
			return ECombatRollResult::Hit;
		}
		return ECombatRollResult::PenetratingHit;
	}
	
	return ECombatRollResult::Miss;
}

ECombatRollResult UGameplayUtilities::DoCombatRoll(FVector4f& Damage, const float Accuracy, const FVector4f Mitigation,
                                                   const float BlockChance, const float BlockValue, const float ParryChance, const float EvadeChance,
                                                   const float GlanceChance, const float GlanceValue, const float CriticalChance, const float CriticalDefense,
                                                   const float CriticalValue, const float PenetrationChance, const float PenetrationValue)
{
	if(UUtilityStatics::Roll1000(Accuracy))
	{
		if(BlockChance > 0)
		{
			if(UUtilityStatics::Roll1000(BlockChance))
			{
				Damage = Damage * (BlockValue / 1000);
				Damage.X = ApplyMitigation(Damage.X, Mitigation.X);
				Damage.Y = ApplyMitigation(Damage.Y, Mitigation.Y);
				Damage.Z = ApplyMitigation(Damage.Z, Mitigation.Z);
				Damage.W = ApplyMitigation(Damage.W, Mitigation.W);
				return ECombatRollResult::Block;		
			}
		}
		if(ParryChance > 0)
		{
			if(UUtilityStatics::Roll1000(ParryChance))
			{
				Damage = Damage * ParryValue;
				Damage.X = ApplyMitigation(Damage.X, Mitigation.X);
				Damage.Y = ApplyMitigation(Damage.Y, Mitigation.Y);
				Damage.Z = ApplyMitigation(Damage.Z, Mitigation.Z);
				Damage.W = ApplyMitigation(Damage.W, Mitigation.W);
				return ECombatRollResult::Parry;
			}
		}
		if(EvadeChance > 0)
		{
			if(UUtilityStatics::Roll1000(EvadeChance))
			{
				Damage = FVector4f::Zero();
				return ECombatRollResult::Evade;
			}
		}
		if(GlanceChance > 0)
		{
			if(UUtilityStatics::Roll1000(GlanceChance))
			{
				Damage = Damage * ((1000 - GlanceValue)/1000);
				Damage.X = ApplyMitigation(Damage.X, Mitigation.X);
				Damage.Y = ApplyMitigation(Damage.Y, Mitigation.Y);
				Damage.Z = ApplyMitigation(Damage.Z, Mitigation.Z);
				Damage.W = ApplyMitigation(Damage.W, Mitigation.W);
				return ECombatRollResult::Glance;
			}
		}
		//do crit here
		if(ApplyCriticalHit(Damage, CriticalChance, CriticalDefense, CriticalValue))
		{
			//critical Hit
			Damage.X = ApplyMitigation(Damage.X, Mitigation.X);
			Damage.Y = ApplyMitigation(Damage.Y, Mitigation.Y);
			Damage.Z = ApplyMitigation(Damage.Z, Mitigation.Z);
			Damage.W = ApplyMitigation(Damage.W, Mitigation.W);
			return ECombatRollResult::CriticalHit;
		}
		if(!UUtilityStatics::Roll1000(PenetrationChance))
		{
			Damage.X = ApplyMitigation(Damage.X, FMath::Max(Mitigation.X - PenetrationValue,0));
			Damage.Y = ApplyMitigation(Damage.Y, FMath::Max(Mitigation.Y - PenetrationValue,0));
			Damage.Z = ApplyMitigation(Damage.Z, FMath::Max(Mitigation.Z - PenetrationValue,0));
			Damage.W = ApplyMitigation(Damage.W, FMath::Max(Mitigation.W - PenetrationValue,0));
			return ECombatRollResult::Hit;
		}
		return ECombatRollResult::PenetratingHit;
	}
	
	return ECombatRollResult::Miss;
}

ECombatRollResult UGameplayUtilities::DoActionCombatRoll(float& Damage, float Accuracy, const float Mitigation,
	const float CriticalChance, const float CriticalDefense, const float CriticalValue, const float PenetrationChance, const float PenetrationValue)
{
	//do crit here
	if(ApplyCriticalHit(Damage, CriticalChance, CriticalDefense, CriticalValue))
	{
		//critical Hit
		Damage = ApplyMitigation(Damage, Mitigation);
		return ECombatRollResult::CriticalHit;
	}
	if(UUtilityStatics::Roll1000(PenetrationChance))
	{
		Damage = ApplyMitigation(Damage, FMath::Max(Mitigation - PenetrationValue,0));
		return ECombatRollResult::PenetratingHit;
	}
	return ECombatRollResult::Hit;
}

float UGameplayUtilities::ApplyMitigation(const float Damage, const float Mitigation)
{
	return Damage * (1 - Mitigation / 1000);
}

FVector4f UGameplayUtilities::ApplyMitigation(const FVector4f Damage, const float Mitigation1, const float Mitigation2, const float Mitigation3,
	const float Mitigation4)
{
	return Damage * (FVector4f::One() - FVector4f(Mitigation1, Mitigation2, Mitigation3,Mitigation4)
		/ FVector4f(1000,1000,1000,1000));
}

bool UGameplayUtilities::ApplyCriticalHit(float& Damage, const float CriticalChance, const float CriticalDefense,
	const float CriticalValue)
{
	if(UUtilityStatics::Roll1000(CriticalChance - CriticalDefense))
	{
		Damage = Damage * ((1000 + CriticalValue) / 1000);
		return true;
	}
	return false;
}

bool UGameplayUtilities::ApplyCriticalHit(FVector4f& Damage, const float CriticalChance, const float CriticalDefense,
                                          const float CriticalValue)
{
	if(UUtilityStatics::Roll1000(CriticalChance - CriticalDefense))
	{
		Damage = Damage * ((1000 + CriticalValue) / 1000);
		return true;
	}
	return false;
}

ECombatRollResult UGameplayUtilities::DoCombatRoll(const float HitChance, const float EvadeChance,
	float GlanceChance)
{
	if(UUtilityStatics::Roll1000(HitChance - EvadeChance))
	{
		if (UUtilityStatics::Roll1000(GlanceChance))
		{
			return ECombatRollResult::Glance;
		}
	}
	return ECombatRollResult::Miss;
}

void UGameplayUtilities::ApplyEffectToTarget(const TSubclassOf<UGameplayEffect>& Effect, const float Level, AActor* Target,
	const AActor* Source, const TArray<FCustomEffectValue>& CustomValues)
{
	UGameplayAbilitySystemComponent * TargetAbilitySystem = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target));
	if(IsValidEnsure(TargetAbilitySystem))
	{
		TargetAbilitySystem->ApplyGameplayEffect(Effect, Level, CustomValues, Source);
	}
}

void UGameplayUtilities::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& Effect, float Level,
	AActor* Source, const TArray<FCustomEffectValue>& CustomValues)
{
	UGameplayAbilitySystemComponent * TargetAbilitySystem = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Source));
	if(IsValidEnsure(TargetAbilitySystem))
	{
		TargetAbilitySystem->ApplyGameplayEffect(Effect, Level, CustomValues, Source);
	}
}

void UGameplayUtilities::RemoveEffect(const TSubclassOf<UGameplayEffect>& Effect, AActor* Source)
{
	UGameplayAbilitySystemComponent * TargetAbilitySystem = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Source));
	if(IsValidEnsure(TargetAbilitySystem))
	{
		TargetAbilitySystem->RemoveGameplayEffect(Effect);
	}
}

void UGameplayUtilities::RunAbility(const FGameplayTag Ability, AActor* Target, AActor* Source, const float Magnitude)
{
	if (UGameplayAbilitySystemComponent * SourceComponent =Cast<UGameplayAbilitySystemComponent>(
				UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Source)))
	{
		SourceComponent->OnAbilityInputPressed(Ability);
		SourceComponent->OnAbilityInputReleased(Ability);
		FGameplayEventData Payload;
		Payload.Instigator = Source;
		Payload.Target = Target;
		Payload.EventMagnitude = Magnitude;
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Source, ImpactEventTag, Payload);
	}
}
