// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/SensorAttributeSet.h"

#include "Attributes/AttributeSetBase.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(SensorStrengthTag, "Sensor.Attribute.Strength", "Strength");

float USensorAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(SensorStrength, AttributeTag);
	return 0;
}

void USensorAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(SensorStrength, Attribute, Value);
}

FGameplayTag USensorAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(SensorStrength, Attribute);
	return FGameplayTag();
}

void USensorAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USensorAttributeSet, SensorStrength, COND_None, REPNOTIFY_Always);
}

void USensorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(USensorAttributeSet, SensorStrength);
