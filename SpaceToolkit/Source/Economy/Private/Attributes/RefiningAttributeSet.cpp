// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/RefiningAttributeSet.h"

#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(RefiningSpeedTag, "Attribute.Refining.Speed", "Refining Speed");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RefiningEfficiencyTag, "Attribute.Refining.Efficiency", "Refining Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RefiningQualityTag, "Attribute.Refining.Quality", "Refining Quality");

float URefiningAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(RefiningSpeed, AttributeTag);
	GET_IF_TAGMATCHES(RefiningEfficiency, AttributeTag);
	GET_IF_TAGMATCHES(RefiningQuality, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void URefiningAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(RefiningSpeed, Attribute, Value);
	SET_IF_TAGMATCHES(RefiningEfficiency, Attribute, Value);
	SET_IF_TAGMATCHES(RefiningQuality, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

void URefiningAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(URefiningAttributeSet, RefiningSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URefiningAttributeSet, RefiningEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URefiningAttributeSet, RefiningQuality, COND_None, REPNOTIFY_Always);
}

void URefiningAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(URefiningAttributeSet, RefiningSpeed)
ATTRIBUTE_IMPLEMENT(URefiningAttributeSet, RefiningEfficiency)
ATTRIBUTE_IMPLEMENT(URefiningAttributeSet, RefiningQuality)
