﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/PowerAttributeSet.h"

#include "Attributes/Equipment/SensorAttributeSet.h"
#include "Net/UnrealNetwork.h"

float UPowerAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ShieldPower, AttributeTag);
	GET_IF_TAGMATCHES(ShieldDistribution, AttributeTag);
	GET_IF_TAGMATCHES(EnginePower, AttributeTag);
	GET_IF_TAGMATCHES(EngineDistribution, AttributeTag);
	GET_IF_TAGMATCHES(BatteryPower, AttributeTag);
	GET_IF_TAGMATCHES(BatteryDistribution, AttributeTag);
	GET_IF_TAGMATCHES(LifeSupportPower, AttributeTag);
	GET_IF_TAGMATCHES(LifeSupportDistribution, AttributeTag);
	GET_IF_TAGMATCHES(SensorPower, AttributeTag);
	GET_IF_TAGMATCHES(SensorDistribution, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UPowerAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ShieldPower, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldDistribution, Attribute, Value);
	SET_IF_TAGMATCHES(EnginePower, Attribute, Value);
	SET_IF_TAGMATCHES(EngineDistribution, Attribute, Value);
	SET_IF_TAGMATCHES(BatteryPower, Attribute, Value);
	SET_IF_TAGMATCHES(BatteryDistribution, Attribute, Value);
	SET_IF_TAGMATCHES(LifeSupportPower, Attribute, Value);
	SET_IF_TAGMATCHES(LifeSupportDistribution, Attribute, Value);
	SET_IF_TAGMATCHES(SensorPower, Attribute, Value);
	SET_IF_TAGMATCHES(SensorDistribution, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UPowerAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ShieldPower, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldDistribution, Attribute);
	CHECK_IF_ATTRIBUTE(EnginePower, Attribute);
	CHECK_IF_ATTRIBUTE(EngineDistribution, Attribute);
	CHECK_IF_ATTRIBUTE(BatteryPower, Attribute);
	CHECK_IF_ATTRIBUTE(BatteryDistribution, Attribute);
	CHECK_IF_ATTRIBUTE(LifeSupportPower, Attribute);
	CHECK_IF_ATTRIBUTE(LifeSupportDistribution, Attribute);
	CHECK_IF_ATTRIBUTE(SensorPower, Attribute);
	CHECK_IF_ATTRIBUTE(SensorDistribution, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UPowerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, ShieldPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, ShieldDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, EnginePower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, EngineDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, BatteryPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, BatteryDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, LifeSupportPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, LifeSupportDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, SensorPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, SensorDistribution, COND_None, REPNOTIFY_Always);
}

void UPowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, ShieldPower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, ShieldDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, EnginePower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, EngineDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, BatteryPower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, BatteryDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, LifeSupportDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, LifeSupportPower);
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, SensorDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, SensorPower)