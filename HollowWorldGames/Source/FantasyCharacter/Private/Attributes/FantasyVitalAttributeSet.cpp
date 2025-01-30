// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasyVitalAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicTag, "Vital.Attributes.Magic", "Magic");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxMagicTag, "Vital.Attributes.MaxMagic", "Max Magic");

float UFantasyVitalAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Magic, AttributeTag);
	GET_IF_TAGMATCHES(MaxMagic, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasyVitalAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Magic, Attribute, Value);
	SET_IF_TAGMATCHES(MaxMagic, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasyVitalAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Magic, Attribute);
	CHECK_IF_ATTRIBUTE(MaxMagic, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFantasyVitalAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyVitalAttributeSet, Magic, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyVitalAttributeSet, MaxMagic, COND_None, REPNOTIFY_Always);
}

void UFantasyVitalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	CAP_ATTRIBUTE(Magic, MaxMagic, Data);
}

ATTRIBUTE_IMPLEMENT(UFantasyVitalAttributeSet, Magic);
ATTRIBUTE_IMPLEMENT(UFantasyVitalAttributeSet, MaxMagic);