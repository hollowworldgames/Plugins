// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/PowerAttributeSet2.h"

#include "Attributes/Equipment/SensorAttributeSet.h"
#include "Net/UnrealNetwork.h"

float UPowerAttributeSet2::GetAttributeValue(FGameplayTag AttributeTag)
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

void UPowerAttributeSet2::SetAttributeValue(FGameplayTag Attribute, float Value)
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

FGameplayTag UPowerAttributeSet2::GetAttributeTag(FGameplayAttribute Attribute)
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

void UPowerAttributeSet2::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, ShieldPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, ShieldDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, EnginePower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, EngineDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, BatteryPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, BatteryDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, LifeSupportPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, LifeSupportDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, SensorPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet2, SensorDistribution, COND_None, REPNOTIFY_Always);
}

void UPowerAttributeSet2::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, ShieldPower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, ShieldDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, EnginePower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, EngineDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, BatteryPower)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, BatteryDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, LifeSupportDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, LifeSupportPower);
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, SensorDistribution)
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet2, SensorPower)