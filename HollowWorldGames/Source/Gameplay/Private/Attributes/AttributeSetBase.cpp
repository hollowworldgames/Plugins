// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/AttributeSetBase.h"

#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
#include "Animation/AnimNode_Inertialization.h"
#include "Components/GameplayAbilitySystemComponent.h"

void UAttributeSetBase::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	
}

FGameplayTag UAttributeSetBase::GetAttributeTag(FGameplayAttribute Attribute)
{
	return FGameplayTag();
}

void UAttributeSetBase::Initialize(UGameplayAbilitySystemComponent * AbilitySystemComponent, float Level, const TArray<FCustomEffectValue>& Attributes) const
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, Level, Attributes);
	}
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (OnAttributeChanged.IsBound())
	{
		OnAttributeChanged.Broadcast(GetAttributeTag(Data.EvaluatedData.Attribute), Data.EvaluatedData.Magnitude);
	}
}
