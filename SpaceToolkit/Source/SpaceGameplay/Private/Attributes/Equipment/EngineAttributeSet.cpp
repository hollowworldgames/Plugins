// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/EngineAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"




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