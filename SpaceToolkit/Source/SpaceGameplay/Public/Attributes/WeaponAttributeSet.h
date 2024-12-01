// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "SpaceGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "WeaponAttributeSet.generated.h"



UCLASS()
class SPACEGAMEPLAY_API UWeaponAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponAccuracy);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponAccuracy);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMinRange);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponMinRange);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMaxRange);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponMaxRange);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMinDamage);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponMinDamage);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMaxDamage);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponMaxDamage);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponCriticalChance);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponCriticalChance);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponCriticalDamage);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponCriticalDamage);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponCooldown);
	ATTRIBUTE_TAG_ACCESSOR(UWeaponAttributeSet, WeaponCooldown);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponAccuracy, Category=Health)
	FGameplayAttributeData WeaponAccuracy;
	UFUNCTION()
	void OnRep_WeaponAccuracy(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMinRange, Category=Health)
	FGameplayAttributeData WeaponMinRange;
	UFUNCTION()
	void OnRep_WeaponMinRange(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMaxRange, Category=Health)
	FGameplayAttributeData WeaponMaxRange;
	UFUNCTION()
	void OnRep_WeaponMaxRange(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponCriticalChance, Category=Health)
	FGameplayAttributeData WeaponCriticalChance;
	UFUNCTION()
	void OnRep_WeaponCriticalChance(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponCriticalDamage, Category=Health)
	FGameplayAttributeData WeaponCriticalDamage;
	UFUNCTION()
	void OnRep_WeaponCriticalDamage(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMinDamage, Category=Health)
	FGameplayAttributeData WeaponMinDamage;
	UFUNCTION()
	void OnRep_WeaponMinDamage(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMaxDamage, Category=Health)
	FGameplayAttributeData WeaponMaxDamage;
	UFUNCTION()
	void OnRep_WeaponMaxDamage(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponCooldown, Category=Health)
	FGameplayAttributeData WeaponCooldown;
	UFUNCTION()
	void OnRep_WeaponCooldown(const FGameplayAttributeData& OldWeaponCooldown) const;
};
