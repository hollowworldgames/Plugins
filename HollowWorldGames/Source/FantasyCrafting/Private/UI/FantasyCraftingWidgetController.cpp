// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/FantasyCraftingWidgetController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Attributes/FantasyCraftingAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UFantasyCraftingWidgetController::BindToAttributes()
{
	Super::BindToAttributes();
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		bool Found = false;
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetProspectingLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnProspectingLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetForestryLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnForestryLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetFarmingLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnFarmingLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetJewelerLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnJewelerLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetHerbalistLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHerbalistLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetLoreMasterLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnLoreMasterLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetWoodWorkerLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnWoodWorkerLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UFantasyCraftingAttributeSet::GetTailorLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnTailorLevelChanged.Broadcast(Data.NewValue);
		});
	}
	PulseAttributes();
}

void UFantasyCraftingWidgetController::PulseAttributes()
{
	Super::PulseAttributes();
	bool Found = false;
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		OnProspectingLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetProspectingLevelAttribute(), Found));
		OnForestryLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetForestryLevelAttribute(), Found));
		OnFarmingLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetFarmingLevelAttribute(), Found));
		OnJewelerLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetJewelerLevelAttribute(), Found));
		OnHerbalistLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetHerbalistLevelAttribute(), Found));
		OnCookLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetCookLevelAttribute(), Found));
		OnBlacksmithLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetBlacksmithLevelAttribute(), Found));
		OnWoodWorkerLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
        	UFantasyCraftingAttributeSet::GetWoodWorkerLevelAttribute(), Found));
		OnLoreMasterLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetLoreMasterLevelAttribute(), Found));
		OnTailorLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(
			UFantasyCraftingAttributeSet::GetTailorLevelAttribute(), Found));
	}
}
