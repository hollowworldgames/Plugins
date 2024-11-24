﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/EngineAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


UE_DEFINE_GAMEPLAY_TAG_COMMENT(EngineThrustTag,"Engine.Attributes.Thrust","Engine Thrust");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnginePowerTag,"Engine.Attributes.Power","Engine Power");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EngineDistributionTag,"Engine.Attributes.Distribution","Engine Distribution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerToThrustTag,"Engine.Attributes.Distribution","Engine Distribution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxRCSThrustTag,"Engine.Attributes.Distribution","Engine Distribution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EngineOnTag,"Engine.State.On","Engine On");

float UEngineAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(EngineThrust, AttributeTag);
	GET_IF_TAGMATCHES(EnginePower, AttributeTag);
	GET_IF_TAGMATCHES(EngineDistribution, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UEngineAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(EngineThrust, Attribute, Value);
	SET_IF_TAGMATCHES(EnginePower, Attribute, Value);
	SET_IF_TAGMATCHES(EngineDistribution, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UEngineAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(EngineThrust, Attribute);
	CHECK_IF_ATTRIBUTE(EnginePower, Attribute);
	CHECK_IF_ATTRIBUTE(EngineDistribution, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UEngineAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineAttributeSet, EngineThrust, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineAttributeSet, EnginePower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineAttributeSet, EngineDistribution, COND_None, REPNOTIFY_Always);
}

void UEngineAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

}

ATTRIBUTE_IMPLEMENT(UEngineAttributeSet, EngineThrust);
ATTRIBUTE_IMPLEMENT(UEngineAttributeSet, EnginePower);
ATTRIBUTE_IMPLEMENT(UEngineAttributeSet, EngineDistribution);