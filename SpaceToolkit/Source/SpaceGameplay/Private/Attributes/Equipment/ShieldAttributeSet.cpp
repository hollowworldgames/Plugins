// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/ShieldAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"



float UShieldAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ShieldPower, AttributeTag);
	GET_IF_TAGMATCHES(ShieldDistribution, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UShieldAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ShieldPower, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldDistribution, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UShieldAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ShieldPower, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldDistribution, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UShieldAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldDistribution, COND_None, REPNOTIFY_Always);
}

void UShieldAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldPower);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldDistribution);
