// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/ConstructionAttributeSet.h"

#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstructionSpeedTag, "Attribute.Construction.Speed", "Construction Speed");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstructionEfficiencyTag, "Attribute.Construction.Efficiency", "Construction Efficiency");

float UConstructionAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ConstructionSpeed, ConstructionSpeedTag);
	GET_IF_TAGMATCHES(ConstructionSpeed, ConstructionEfficiencyTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UConstructionAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ConstructionSpeed, ConstructionSpeedTag, Value);
	SET_IF_TAGMATCHES(ConstructionEfficiency, ConstructionEfficiencyTag, Value);
	Super::SetAttributeValue(Attribute, Value);
}

void UConstructionAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UConstructionAttributeSet, ConstructionSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UConstructionAttributeSet, ConstructionEfficiency, COND_None, REPNOTIFY_Always);
}

void UConstructionAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UConstructionAttributeSet, ConstructionSpeed)
ATTRIBUTE_IMPLEMENT(UConstructionAttributeSet, ConstructionEfficiency)
