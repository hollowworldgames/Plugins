// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/RPGCombatAttributeSet.h"

#include "Net/UnrealNetwork.h"

float URPGCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(HitChance, AttributeTag);
	GET_IF_TAGMATCHES(GlancingBlowChance, AttributeTag);
	GET_IF_TAGMATCHES(EvadeChance, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void URPGCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(HitChance, Attribute, Value);
	SET_IF_TAGMATCHES(GlancingBlowChance, Attribute, Value);
	SET_IF_TAGMATCHES(EvadeChance, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag URPGCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(HitChance, Attribute);
	CHECK_IF_ATTRIBUTE(GlancingBlowChance, Attribute);
	CHECK_IF_ATTRIBUTE(EvadeChance, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void URPGCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, HitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, GlancingBlowChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGCombatAttributeSet, EvadeChance, COND_None, REPNOTIFY_Always);
}

void URPGCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

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

ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, HitChance);
ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, BlockChance);
ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, BlockValue);
ATTRIBUTE_IMPLEMENT(URPGMeleeCombatAttributeSet, ParryChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, GlancingBlowChance);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, GlancingBlowValue);
ATTRIBUTE_IMPLEMENT(URPGCombatAttributeSet, EvadeChance);
