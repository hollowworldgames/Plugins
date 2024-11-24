// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/AttributeSetBase.h"

#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
#include "Animation/AnimNode_Inertialization.h"

void UAttributeSetBase::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	
}

FGameplayTag UAttributeSetBase::GetAttributeTag(FGameplayAttribute Attribute)
{
	return FGameplayTag();
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (OnAttributeChanged.IsBound())
	{
		OnAttributeChanged.Broadcast(GetAttributeTag(Data.EvaluatedData.Attribute), Data.EvaluatedData.Magnitude);
	}
}
