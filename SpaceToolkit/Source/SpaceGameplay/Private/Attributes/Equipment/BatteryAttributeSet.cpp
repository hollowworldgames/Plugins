// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/BatteryAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerCapacityTag, "Battery.Attribute.PowerCapacity", "Power Capacity");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(StoredPowerTag,"Battery.Attribute.StoredPower","Stored Power");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BatteryPowerTag,"Battery.Attribute.BatteryPower","Battery Power");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BatteryDistributionTag,"Battery.Attribute.BatteryDistribution","Battery Distribution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BatteryOnTag,"Battery.Status.On","Battery On");

float UBatteryAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(PowerCapacity, AttributeTag);
	GET_IF_TAGMATCHES(StoredPower, AttributeTag);
	GET_IF_TAGMATCHES(BatteryPower, AttributeTag);
	GET_IF_TAGMATCHES(BatteryDistribution, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UBatteryAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(PowerCapacity, Attribute, Value);
	SET_IF_TAGMATCHES(StoredPower, Attribute, Value);
	SET_IF_TAGMATCHES(BatteryPower, Attribute, Value);
	SET_IF_TAGMATCHES(BatteryDistribution, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UBatteryAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(StoredPower, Attribute);
	CHECK_IF_ATTRIBUTE(BatteryPower, Attribute);
	CHECK_IF_ATTRIBUTE(BatteryDistribution, Attribute);
	CHECK_IF_ATTRIBUTE(PowerCapacity, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UBatteryAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UBatteryAttributeSet, PowerCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBatteryAttributeSet, StoredPower, COND_None, REPNOTIFY_Always);
}

void UBatteryAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(PowerCapacity, StoredPower, Data);
}

ATTRIBUTE_IMPLEMENT(UBatteryAttributeSet, PowerCapacity);
ATTRIBUTE_IMPLEMENT(UBatteryAttributeSet, StoredPower);
