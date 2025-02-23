// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/GameplayPrimaryWidgetController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UGameplayPrimaryWidgetController::BindToAttributes()
{
	Super::BindToAttributes();
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetStrengthAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnStrengthChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetAgilityAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnAgilityChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetPrecisionAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnPrecisionChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetIntelligenceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnIntelligenceChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetWisdomAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnWisdomChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetLuckAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnLuckChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetConstitutionAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnConstitutionChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetEnduranceAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnEnduranceChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPrimaryAttributeSet::GetCharismaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnCharismaChanged.Broadcast(Data.NewValue);
		});
	}
}

void UGameplayPrimaryWidgetController::PulseAttributes()
{
	Super::PulseAttributes();
	bool Found = false;
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		OnStrengthChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetStrengthAttribute(), Found));
		OnAgilityChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetAgilityAttribute(), Found));
		OnPrecisionChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetPrecisionAttribute(), Found));
		OnWisdomChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetWisdomAttribute(), Found));
		OnIntelligenceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetIntelligenceAttribute(), Found));
		OnLuckChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetLuckAttribute(), Found));
		OnConstitutionChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetConstitutionAttribute(), Found));
		OnEnduranceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetEnduranceAttribute(), Found));
		OnCharismaChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UPrimaryAttributeSet::GetCharismaAttribute(), Found));
	}
}
