// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/RPGAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void URPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Experience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Energy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, EnergyMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Precision, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Accuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, BlockValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, GlancingBlowChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, ParryChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, EvadeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Penetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CriticalValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CriticalDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Mitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Mitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Mitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Mitigation4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DamageBoost1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DamageBoost2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DamageBoost3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DamageBoost4, COND_None, REPNOTIFY_Always);
}

void URPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(Health, HealthMax, Data);
	CAP_ATTRIBUTE(Energy, EnergyMax, Data);

	PROCESS_INCOMING_DAMAGE(IncomingDamage1, Health, Data);
	PROCESS_INCOMING_DAMAGE(IncomingDamage2, Health, Data);
	PROCESS_INCOMING_DAMAGE(IncomingDamage3, Health, Data);
	PROCESS_INCOMING_DAMAGE(IncomingDamage4, Health, Data);
	
	PROCESS_INCOMING_EXPERIENCE(IncomingExperience, Experience, LevelFromXP, Level, OnLevelChanged, Data);
	PROCESS_INCOMING_HEALING(IncomingHealing, Health, Data);
}


ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Level);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Experience);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Health);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, HealthMax);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Energy);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, EnergyMax);

ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Armor);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Mitigation1);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Mitigation2);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Mitigation3);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Mitigation4);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, DamageBoost1);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, DamageBoost2);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, DamageBoost3);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, DamageBoost4);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Accuracy);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, BlockChance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, BlockValue);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, GlancingBlowChance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, ParryChance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, EvadeChance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Penetration);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, CriticalChance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, CriticalValue);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, CriticalDefense);

ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Strength);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Agility);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Precision);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Luck);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Constitution);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Endurance);