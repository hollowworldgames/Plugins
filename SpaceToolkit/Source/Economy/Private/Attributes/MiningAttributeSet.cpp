// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/MiningAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(MiningSpeedTag, "Attribute.Mining.Speed", "Mining Speed");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MiningEfficiencyTag, "Attribute.Mining.Efficiency", "Mining Efficiency");

float UMiningAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(MiningSpeed, MiningSpeedTag);
	GET_IF_TAGMATCHES(MiningSpeed, MiningEfficiencyTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UMiningAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(MiningSpeed, MiningSpeedTag, Value);
	SET_IF_TAGMATCHES(MiningEfficiency, MiningEfficiencyTag, Value);
	Super::SetAttributeValue(Attribute, Value);
}

void UMiningAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMiningAttributeSet, MiningSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMiningAttributeSet, MiningEfficiency, COND_None, REPNOTIFY_Always);
}

void UMiningAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UMiningAttributeSet, MiningSpeed)
ATTRIBUTE_IMPLEMENT(UMiningAttributeSet, MiningEfficiency)
