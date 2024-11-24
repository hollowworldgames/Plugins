// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/RPGAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

float URPGAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Level, AttributeTag);
	GET_IF_TAGMATCHES(Health, AttributeTag);
	GET_IF_TAGMATCHES(HealthMax, AttributeTag);
	GET_IF_TAGMATCHES(Energy, AttributeTag);
	GET_IF_TAGMATCHES(EnergyMax, AttributeTag);
	GET_IF_TAGMATCHES(Strength, AttributeTag);
	GET_IF_TAGMATCHES(Agility, AttributeTag);
	GET_IF_TAGMATCHES(Precision, AttributeTag);
	GET_IF_TAGMATCHES(Luck, AttributeTag);
	GET_IF_TAGMATCHES(Intelligence, AttributeTag);
	GET_IF_TAGMATCHES(Wisdom, AttributeTag);
	GET_IF_TAGMATCHES(Constitution, AttributeTag);
	GET_IF_TAGMATCHES(Endurance, AttributeTag);
	GET_IF_TAGMATCHES(Charisma, AttributeTag);
	GET_IF_TAGMATCHES(Accuracy, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation1, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation2, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation3, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation4, AttributeTag);
	GET_IF_TAGMATCHES(Resistance1, AttributeTag);
	GET_IF_TAGMATCHES(Resistance2, AttributeTag);
	GET_IF_TAGMATCHES(Resistance3, AttributeTag);
	GET_IF_TAGMATCHES(Resistance4, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost1, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost2, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost3, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost4, AttributeTag);
	GET_IF_TAGMATCHES(Accuracy, AttributeTag);
	GET_IF_TAGMATCHES(BlockChance, AttributeTag);
	GET_IF_TAGMATCHES(BlockValue, AttributeTag);
	GET_IF_TAGMATCHES(GlancingBlowChance, AttributeTag);
	GET_IF_TAGMATCHES(ParryChance, AttributeTag);
	GET_IF_TAGMATCHES(EvadeChance, AttributeTag);
	GET_IF_TAGMATCHES(Penetration, AttributeTag);
	GET_IF_TAGMATCHES(CriticalChance, AttributeTag);
	GET_IF_TAGMATCHES(CriticalValue, AttributeTag);
	GET_IF_TAGMATCHES(CriticalDefense, AttributeTag);
	return 0;
}

void URPGAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Strength, Attribute, Value);
	SET_IF_TAGMATCHES(Agility, Attribute, Value);
	SET_IF_TAGMATCHES(Precision, Attribute, Value);
	SET_IF_TAGMATCHES(Luck, Attribute, Value);
	SET_IF_TAGMATCHES(Intelligence, Attribute, Value);
	SET_IF_TAGMATCHES(Wisdom, Attribute, Value);
	SET_IF_TAGMATCHES(Constitution, Attribute, Value);
	SET_IF_TAGMATCHES(Endurance, Attribute, Value);
	SET_IF_TAGMATCHES(Charisma, Attribute, Value);
}

FGameplayTag URPGAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Level, Attribute);
	CHECK_IF_ATTRIBUTE(Health, Attribute);
	CHECK_IF_ATTRIBUTE(HealthMax, Attribute);
	CHECK_IF_ATTRIBUTE(Energy, Attribute);
	CHECK_IF_ATTRIBUTE(EnergyMax, Attribute);
	CHECK_IF_ATTRIBUTE(Strength, Attribute);
	CHECK_IF_ATTRIBUTE(Agility, Attribute);
	CHECK_IF_ATTRIBUTE(Precision, Attribute);
	CHECK_IF_ATTRIBUTE(Luck, Attribute);
	CHECK_IF_ATTRIBUTE(Intelligence, Attribute);
	CHECK_IF_ATTRIBUTE(Wisdom, Attribute);
	CHECK_IF_ATTRIBUTE(Constitution, Attribute);
	CHECK_IF_ATTRIBUTE(Endurance, Attribute);
	CHECK_IF_ATTRIBUTE(Charisma, Attribute);
	CHECK_IF_ATTRIBUTE(Accuracy, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation4, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance1, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance2, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance3, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance4, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost1, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost2, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost3, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost4, Attribute);
	CHECK_IF_ATTRIBUTE(Accuracy, Attribute);
	CHECK_IF_ATTRIBUTE(BlockChance, Attribute);
	CHECK_IF_ATTRIBUTE(BlockValue, Attribute);
	CHECK_IF_ATTRIBUTE(GlancingBlowChance, Attribute);
	CHECK_IF_ATTRIBUTE(ParryChance, Attribute);
	CHECK_IF_ATTRIBUTE(EvadeChance, Attribute);
	CHECK_IF_ATTRIBUTE(Penetration, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalChance, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalValue, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalDefense, Attribute);
	return Super::GetAttributeTag(Attribute);
}

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
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Wisdom, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
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
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Resistance1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Resistance2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Resistance3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Resistance4, COND_None, REPNOTIFY_Always);
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

	PROCESS_INCOMING_DAMAGE(IncomingDamage1, Health, Data, OnDead);
	PROCESS_INCOMING_DAMAGE(IncomingDamage2, Health, Data, OnDead);
	PROCESS_INCOMING_DAMAGE(IncomingDamage3, Health, Data, OnDead);
	PROCESS_INCOMING_DAMAGE(IncomingDamage4, Health, Data, OnDead);
	
	
	
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
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Resistance1);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Resistance2);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Resistance3);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Resistance4);
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
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Intelligence);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Wisdom);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Constitution);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Endurance);
ATTRIBUTE_IMPLEMENT(URPGAttributeSet, Charisma);