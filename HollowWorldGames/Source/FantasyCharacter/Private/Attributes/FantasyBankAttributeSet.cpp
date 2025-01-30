// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasyBankAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(MoneyTag, "Bank.Attribute.Money", "Money");

float UFantasyBankAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Money, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasyBankAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Money, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasyBankAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Money, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFantasyBankAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyBankAttributeSet, Money, COND_None, REPNOTIFY_Always);
}

void UFantasyBankAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UFantasyBankAttributeSet, Money);