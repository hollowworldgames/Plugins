// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayUtilities.h"

#include "UtilityStatics.h"


float UGameplayUtilities::ParryValue = 0.4f;
float UGameplayUtilities::GlanceValue = 0.5f;

ECombatRollResult UGameplayUtilities::DoCombatRoll(float& Damage, float Accuracy, float Mitigation,
                                                                float BlockChance, float BlockValue, float ParryChance, float EvadeChance,
                                                                float GlanceChance, float CriticalChance, float CriticalDefense, float CriticalValue,
                                                                float PenetrationChance)
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
				Damage = Damage * GlanceChance;
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

float UGameplayUtilities::ApplyMitigation(float Damage, float Mitigation)
{
	return Damage * (Mitigation / 1000);
}

bool UGameplayUtilities::ApplyCriticalHit(float& Damage, float CriticalChance, float CriticalDefense,
	float CriticalValue)
{
	if(UUtilityStatics::Roll1000(CriticalChance - CriticalDefense))
	{
		Damage = Damage * ((1000 + CriticalValue) / 1000);
		return true;
	}
	return false;
}
