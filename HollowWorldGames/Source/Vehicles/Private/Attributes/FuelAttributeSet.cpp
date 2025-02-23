// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/FuelAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelCapacityTag, "Vehicle.Attribute.Fuel.Capacity", "Fuel Capacity")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelMaxCapacityTag, "Vehicle.Attribute.Fuel.MaxCapacity", "Fuel Max Capacity")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelFlowTag, "Vehicle.Attribute.Fuel.Flow", "Fuel Flow")

float UFuelAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(FuelCapacity, AttributeTag);
	GET_IF_TAGMATCHES(FuelMaxCapacity, AttributeTag);
	GET_IF_TAGMATCHES(FuelFlow, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFuelAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(FuelCapacity, Attribute, Value);
	SET_IF_TAGMATCHES(FuelMaxCapacity, Attribute, Value);
	SET_IF_TAGMATCHES(FuelFlow, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFuelAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(FuelCapacity, Attribute);
	CHECK_IF_ATTRIBUTE(FuelMaxCapacity, Attribute);
	CHECK_IF_ATTRIBUTE(FuelFlow, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFuelAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet, FuelCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet, FuelMaxCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet, FuelFlow, COND_None, REPNOTIFY_Always);
}

void UFuelAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	CAP_ATTRIBUTE(FuelCapacity, FuelMaxCapacity, Data);
}

ATTRIBUTE_IMPLEMENT(UFuelAttributeSet, FuelCapacity);
ATTRIBUTE_IMPLEMENT(UFuelAttributeSet, FuelMaxCapacity);
ATTRIBUTE_IMPLEMENT(UFuelAttributeSet, FuelFlow);
