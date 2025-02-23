// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/GameplayVitalWidgetController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UGameplayVitalWidgetController::BindToAttributes()
{
	Super::BindToAttributes();
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetHealthAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetMaxHealthAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetEnergyAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnEnergyChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetMaxEnergyAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxEnergyChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetManaAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UVitalAttributeSet::GetMaxManaAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UExperienceAttributeSet::GetLevelAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnLevelChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UExperienceAttributeSet::GetExperienceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnExperienceChanged.Broadcast(Data.NewValue);
		});
	}
	PulseAttributes();
}

void UGameplayVitalWidgetController::PulseAttributes()
{
	Super::PulseAttributes();
	bool Found = false;
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		OnHealthChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetHealthAttribute(), Found));
		OnMaxHealthChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetMaxHealthAttribute(), Found));
		OnEnergyChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetEnergyAttribute(), Found));
		OnMaxEnergyChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetMaxEnergyAttribute(), Found));
		OnManaChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetManaAttribute(), Found));
		OnMaxManaChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UVitalAttributeSet::GetMaxManaAttribute(), Found));
		OnLevelChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UExperienceAttributeSet::GetLevelAttribute(), Found));
		OnExperienceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UExperienceAttributeSet::GetExperienceAttribute(), Found));
	}
}
