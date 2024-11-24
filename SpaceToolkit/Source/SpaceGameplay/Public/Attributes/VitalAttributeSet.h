// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"

#include "VitalAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDead);

SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HealthTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxHealthTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LevelTag);

UCLASS()
class SPACEGAMEPLAY_API UVitalAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Level);
	ATTRIBUTE_TAG_ACCESSOR(UVitalAttributeSet, Level);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Health);
	ATTRIBUTE_TAG_ACCESSOR(UVitalAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxHealth);
	ATTRIBUTE_TAG_ACCESSOR(UVitalAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, IncomingDamage);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, IncomingHealing);
	UPROPERTY()
	FOnDead OnDead;
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Level, Category=Health)
	FGameplayAttributeData Level;

	UFUNCTION()
	void OnRep_Level(const FGameplayAttributeData& OldLevel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Health, Category=Health)
	FGameplayAttributeData Health;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxHealth, Category=Health)
	FGameplayAttributeData MaxHealth;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayAttributeData IncomingDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayAttributeData IncomingHealing;

};
