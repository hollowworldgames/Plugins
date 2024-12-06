// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/RPGCombatAttributeSet.h"

#include "Net/UnrealNetwork.h"

float URPGCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(DamageBoost1, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost2, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost3, AttributeTag);
	GET_IF_TAGMATCHES(DamageBoost4, AttributeTag);
	GET_IF_TAGMATCHES(Resistance1, AttributeTag);
	GET_IF_TAGMATCHES(Resistance2, AttributeTag);
	GET_IF_TAGMATCHES(Resistance3, AttributeTag);
	GET_IF_TAGMATCHES(Resistance4, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation1, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation2, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation3, AttributeTag);
	GET_IF_TAGMATCHES(Mitigation4, AttributeTag);
	GET_IF_TAGMATCHES(HitChance, AttributeTag);
	GET_IF_TAGMATCHES(GlancingBlowChance, AttributeTag);
	GET_IF_TAGMATCHES(EvadeChance, AttributeTag);
	GET_IF_TAGMATCHES(CriticalChance, AttributeTag);
	GET_IF_TAGMATCHES(CriticalValue, AttributeTag);
	GET_IF_TAGMATCHES(CriticalDefense, AttributeTag);
	GET_IF_TAGMATCHES(Penetration, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void URPGCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Penetration, Attribute, Value);
	SET_IF_TAGMATCHES(DamageBoost1, Attribute, Value);
	SET_IF_TAGMATCHES(DamageBoost2, Attribute, Value);
	SET_IF_TAGMATCHES(DamageBoost3, Attribute, Value);
	SET_IF_TAGMATCHES(DamageBoost4, Attribute, Value);
	SET_IF_TAGMATCHES(Resistance1, Attribute, Value);
	SET_IF_TAGMATCHES(Resistance2, Attribute, Value);
	SET_IF_TAGMATCHES(Resistance3, Attribute, Value);
	SET_IF_TAGMATCHES(Resistance4, Attribute, Value);
	SET_IF_TAGMATCHES(Mitigation1, Attribute, Value);
	SET_IF_TAGMATCHES(Mitigation2, Attribute, Value);
	SET_IF_TAGMATCHES(Mitigation3, Attribute, Value);
	SET_IF_TAGMATCHES(Mitigation4, Attribute, Value);
	SET_IF_TAGMATCHES(HitChance, Attribute, Value);
	SET_IF_TAGMATCHES(GlancingBlowChance, Attribute, Value);
	SET_IF_TAGMATCHES(EvadeChance, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalChance, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalValue, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalDefense, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag URPGCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(DamageBoost1, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost2, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost3, Attribute);
	CHECK_IF_ATTRIBUTE(DamageBoost4, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance1, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance2, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance3, Attribute);
	CHECK_IF_ATTRIBUTE(Resistance4, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(Mitigation4, Attribute);
	CHECK_IF_ATTRIBUTE(HitChance, Attribute);
	CHECK_IF_ATTRIBUTE(GlancingBlowChance, Attribute);
	CHECK_IF_ATTRIBUTE(EvadeChance, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalChance, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalValue, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalDefense, Attribute);
	CHECK_IF_ATTRIBUTE(Penetration, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void URPGCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Mitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Mitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Mitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Mitigation4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Resistance1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Resistance2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Resistance3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Resistance4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, DamageBoost1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, DamageBoost2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, DamageBoost3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, DamageBoost4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, HitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, GlancingBlowChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, EvadeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, CriticalValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, CriticalDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, Penetration, COND_None, REPNOTIFY_Always);
}

void URPGCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, DamageBoost1);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, DamageBoost2);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, DamageBoost3);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, DamageBoost4);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Mitigation1);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Mitigation2);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Mitigation3);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Mitigation4);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Resistance1);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Resistance2);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Resistance3);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Resistance4);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, HitChance);

float URPGMeleeCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(BlockChance, AttributeTag);
	GET_IF_TAGMATCHES(BlockValue, AttributeTag);
	GET_IF_TAGMATCHES(ParryChance, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void URPGMeleeCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(BlockChance, Attribute, Value);
	SET_IF_TAGMATCHES(BlockValue, Attribute, Value);
	SET_IF_TAGMATCHES(ParryChance, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag URPGMeleeCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(BlockChance, Attribute);
	CHECK_IF_ATTRIBUTE(BlockValue, Attribute);
	CHECK_IF_ATTRIBUTE(ParryChance, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void URPGMeleeCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGMeleeCombatAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGMeleeCombatAttributeSet, BlockValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGMeleeCombatAttributeSet, ParryChance, COND_None, REPNOTIFY_Always);
}

void URPGMeleeCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, BlockChance);
ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, BlockValue);
ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, ParryChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, GlancingBlowChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, GlancingBlowValue);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, EvadeChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Armor);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, Penetration);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, PenetrationValue);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, CriticalChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, CriticalValue);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, CriticalDefense);