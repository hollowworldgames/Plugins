// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Attributes/CombatAttributeSet.h"

#include "Attributes/AttributeTags.h"
#include "Net/UnrealNetwork.h"

float UCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(CriticalChance, AttributeTag);
	GET_IF_TAGMATCHES(CriticalValue, AttributeTag);
	GET_IF_TAGMATCHES(CriticalDefense, AttributeTag);
	GET_IF_TAGMATCHES(Penetration, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Penetration, Attribute, Value);
	SET_IF_TAGMATCHES(PenetrationValue, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalChance, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalValue, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalDefense, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(CriticalChance, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalValue, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalDefense, Attribute);
	CHECK_IF_ATTRIBUTE(Penetration, Attribute);
	CHECK_IF_ATTRIBUTE(PenetrationValue, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, Penetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, PenetrationValue, COND_None, REPNOTIFY_Always);
}

void UCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, Armor);
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, Penetration);
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, PenetrationValue);
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalChance);
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalValue);
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalDefense);