// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayUtilities.h"

#include "UtilityStatics.h"


float UGameplayUtilities::ParryValue = 0.4f;

ECombatRollResult UGameplayUtilities::DoCombatRoll(FVector4f& Damage, float Accuracy, FVector4f Mitigation,
                                                                float BlockChance, float BlockValue, float ParryChance, float EvadeChance,
                                                                float GlanceChance, float GlanceValue, float CriticalChance, float CriticalDefense, float CriticalValue,
                                                                float PenetrationChance, float PenetrationValue)
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

float UGameplayUtilities::ApplyMitigation(float Damage, float Mitigation)
{
	return Damage * (1 - Mitigation / 1000);
}

FVector4f UGameplayUtilities::ApplyMitigation(FVector4f Damage, float Mitigation1, float Mitigation2, float Mitigation3,
	float Mitigation4)
{
	return Damage * (FVector4f::One() - FVector4f(Mitigation1, Mitigation2, Mitigation3,Mitigation4)
		/ FVector4f(1000,1000,1000,1000));
}

bool UGameplayUtilities::ApplyCriticalHit(FVector4f& Damage, float CriticalChance, float CriticalDefense,
                                          float CriticalValue)
{
	if(UUtilityStatics::Roll1000(CriticalChance - CriticalDefense))
	{
		Damage = Damage * ((1000 + CriticalValue) / 1000);
		return true;
	}
	return false;
}

ECombatRollResult UGameplayUtilities::DoCombatRoll(float HitChance, float EvadeChance,
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
