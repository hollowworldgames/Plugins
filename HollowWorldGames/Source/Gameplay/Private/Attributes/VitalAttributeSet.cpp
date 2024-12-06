// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/VitalAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

float UVitalAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Level, AttributeTag);
	GET_IF_TAGMATCHES(Health, AttributeTag);
	GET_IF_TAGMATCHES(MaxHealth, AttributeTag);
	GET_IF_TAGMATCHES(Energy, AttributeTag);
	GET_IF_TAGMATCHES(MaxEnergy, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UVitalAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Level, Attribute, Value);
	SET_IF_TAGMATCHES(Health, Attribute, Value);
	SET_IF_TAGMATCHES(MaxHealth, Attribute, Value);
	SET_IF_TAGMATCHES(Energy, Attribute, Value);
	SET_IF_TAGMATCHES(MaxEnergy, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UVitalAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Level, Attribute);
	CHECK_IF_ATTRIBUTE(Health, Attribute);
	CHECK_IF_ATTRIBUTE(MaxHealth, Attribute);
	CHECK_IF_ATTRIBUTE(Energy, Attribute);
	CHECK_IF_ATTRIBUTE(MaxEnergy, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UVitalAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UVitalAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVitalAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVitalAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVitalAttributeSet, Energy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVitalAttributeSet, MaxEnergy, COND_None, REPNOTIFY_Always);
}

void UVitalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);


	CAP_ATTRIBUTE(Health, MaxHealth, Data);
	CAP_ATTRIBUTE(Energy, MaxEnergy, Data);

	PROCESS_INCOMING_DAMAGE(IncomingDamage, Health, Data, OnDead)
	PROCESS_INCOMING_HEALING(IncomingHealing, Health, Data);
}

ATTRIBUTE_IMPLEMENT(UVitalAttributeSet, Level);
ATTRIBUTE_IMPLEMENT(UVitalAttributeSet, Health);
ATTRIBUTE_IMPLEMENT(UVitalAttributeSet, MaxHealth);
ATTRIBUTE_IMPLEMENT(UVitalAttributeSet, Energy);
ATTRIBUTE_IMPLEMENT(UVitalAttributeSet, MaxEnergy);