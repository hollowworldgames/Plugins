// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/LifeSupportAttributeSet.h"

#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(LifeSupportPowerTag,"LifeSupport.Attributes.Power","Life Support Power");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LifeSupportPowerNeedTag,"LifeSupport.Attributes.PowerNeed","Life Support Power Need");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AirQualityTag,"LifeSupport.Attributes.AirQuality","Life Support Air Quality");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PurificationRateTag,"LifeSupport.Attributes.PurificationRate","Life Support Purification Rate");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LifeSupportOnTag,"LifeSupport.Status.On","Life Support On");

float ULifeSupportAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(LifeSupportPower, AttributeTag);
	GET_IF_TAGMATCHES(LifeSupportPowerNeed, AttributeTag);
	GET_IF_TAGMATCHES(AirQuality, AttributeTag);
	GET_IF_TAGMATCHES(PurificationRate, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void ULifeSupportAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(LifeSupportPower, Attribute, Value);
	SET_IF_TAGMATCHES(LifeSupportPowerNeed, Attribute, Value);
	SET_IF_TAGMATCHES(AirQuality, Attribute, Value);
	SET_IF_TAGMATCHES(PurificationRate, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag ULifeSupportAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(LifeSupportPower, Attribute);
	CHECK_IF_ATTRIBUTE(LifeSupportPowerNeed, Attribute);
	CHECK_IF_ATTRIBUTE(AirQuality, Attribute);
	CHECK_IF_ATTRIBUTE(PurificationRate, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void ULifeSupportAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(ULifeSupportAttributeSet, LifeSupportPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULifeSupportAttributeSet, AirQuality, COND_None, REPNOTIFY_Always);
}

void ULifeSupportAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(ULifeSupportAttributeSet, LifeSupportPower);
ATTRIBUTE_IMPLEMENT(ULifeSupportAttributeSet, AirQuality);
