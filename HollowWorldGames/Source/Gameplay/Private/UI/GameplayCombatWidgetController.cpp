// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/GameplayCombatWidgetController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Attributes/CombatAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UGameplayCombatWidgetController::BindToAttributes()
{
	Super::BindToAttributes();

	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		bool Found = false;
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetPenetrationAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnPenetrationChanged.Broadcast(Data.NewValue);
		});
		OnPenetrationChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetPenetrationAttribute(), Found));
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetPenetrationValueAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnPenetrationValueChanged.Broadcast(Data.NewValue);
		});
		OnPenetrationValueChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetPenetrationAttribute(), Found));
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetCriticalChanceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnCriticalChanceChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetCriticalValueAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnCriticalValueChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetCriticalDefenseAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnCriticalDefenseChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCombatAttributeSet::GetArmorAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnArmorChanged.Broadcast(Data.NewValue);
		});
	}
	PulseAttributes();
}

void UGameplayCombatWidgetController::PulseAttributes()
{
	Super::PulseAttributes();
	bool Found = false;
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		OnPenetrationChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetPenetrationAttribute(), Found));
		OnPenetrationValueChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetPenetrationValueAttribute(), Found));
		OnCriticalChanceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetCriticalChanceAttribute(), Found));
		OnCriticalValueChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetCriticalValueAttribute(), Found));
		OnCriticalDefenseChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetCriticalDefenseAttribute(), Found));
		OnArmorChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(UCombatAttributeSet::GetArmorAttribute(), Found));
	}
}

void UGameplayRPGCombatWidgetController::BindToAttributes()
{
	Super::BindToAttributes();
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		bool Found = false;
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(URPGCombatAttributeSet::GetHitChanceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHitChanceChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(URPGCombatAttributeSet::GetGlancingBlowChanceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnGlancingBlowChanceChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(URPGCombatAttributeSet::GetGlancingBlowValueAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnGlancingBlowValueChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(URPGCombatAttributeSet::GetEvadeChanceAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnEvadeChanceChanged.Broadcast(Data.NewValue);
		});
	}
	PulseAttributes();
}

void UGameplayRPGCombatWidgetController::PulseAttributes()
{
	Super::PulseAttributes();
	bool Found = false;
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
	if (IsValidEnsure(AbilitySystemComponent))
	{
		OnHitChanceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(URPGCombatAttributeSet::GetHitChanceAttribute(), Found));
		OnGlancingBlowChanceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(URPGCombatAttributeSet::GetGlancingBlowChanceAttribute(), Found));
		OnGlancingBlowValueChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(URPGCombatAttributeSet::GetGlancingBlowValueAttribute(), Found));
		OnEvadeChanceChanged.Broadcast(AbilitySystemComponent->GetGameplayAttributeValue(URPGCombatAttributeSet::GetEvadeChanceAttribute(), Found));
	}
}
