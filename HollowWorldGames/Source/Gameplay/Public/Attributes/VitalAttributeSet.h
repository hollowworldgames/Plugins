// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeTags.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"

#include "VitalAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDead);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComponentDead, FGameplayTag, Component);


UCLASS()
class GAMEPLAY_API UVitalAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	//ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Level);
	//ATTRIBUTE_TAG_ACCESSOR(UVitalAttributeSet, Level);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Energy);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxEnergy);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxMana);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, IncomingDamage);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, IncomingHealing);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, HealthRegen);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, EnergyRegen);
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, ManaRegen);
	UPROPERTY()
	FOnDead OnDead;
	UPROPERTY()
	FOnComponentDead OnComponentDead;
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Health, Category=Health)
	FGameplayAttributeData Health;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxHealth, Category=Health)
	FGameplayAttributeData MaxHealth;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxEnergy) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Energy, Category=Health)
	FGameplayAttributeData Energy;

	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldEnergy) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxEnergy, Category=Health)
	FGameplayAttributeData MaxEnergy;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mana, Category=Health)
	FGameplayAttributeData Mana;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxMana, Category=Health)
	FGameplayAttributeData MaxMana;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	UFUNCTION()
	void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayAttributeData IncomingDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayAttributeData IncomingHealing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HealthRegen, Category=Health)
	FGameplayAttributeData HealthRegen;

	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnergyRegen, Category=Health)
	FGameplayAttributeData EnergyRegen;

	UFUNCTION()
	void OnRep_EnergyRegen(const FGameplayAttributeData& OldEnergyRegen) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ManaRegen, Category=Mana)
	FGameplayAttributeData ManaRegen;

	UFUNCTION()
	void OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen) const;
};
