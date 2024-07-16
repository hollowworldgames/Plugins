// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "SpaceCharacterAttributes.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTER_API USpaceCharacterAttributes : public UAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Health);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Health);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, HealthMax);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, HealthMax);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Energy);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Energy);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, EnergyMax);

	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, IncomingPhysicalDamage);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, IncomingEnergyDamage);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, IncomingHealing);

	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, GlancingBlowChance);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, GlancingBlowChance);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, ParryChance);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, ParryChance);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, EvadeChance);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, EvadeChance);
	
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, EnergyMax);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Strength);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Strength);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Agility);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Agility);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Precision);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Precision);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Luck);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Luck);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Constitution);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Constitution);
	ATTRIBUTE_ACCESSORS(USpaceCharacterAttributes, Endurance);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterAttributes, Endurance);
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//Health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Health, Category=Health)
	FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HealthTag;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HealthMax, Category=Health)
	FGameplayAttributeData HealthMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HealthMaxTag;
	UFUNCTION()
	void OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Energy, Category=Health)
	FGameplayAttributeData Energy;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag EnergyTag;
	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldEnergy) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnergyMax, Category=Health)
	FGameplayAttributeData EnergyMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag EnergyMaxTag;
	UFUNCTION()
	void OnRep_EnergyMax(const FGameplayAttributeData& OldEnergyMax) const;

	//Damage Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingPhysicalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingEnergyDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingHealing;
	//Combat Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowChance, Category=Combat)
	FGameplayAttributeData GlancingBlowChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag GlancingBlowChanceTag;
	UFUNCTION()
	void OnRep_GlancingBlowChance(const FGameplayAttributeData& OldGlancingBlowChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ParryChance, Category=Combat)
	FGameplayAttributeData ParryChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag ParryChanceTag;
	UFUNCTION()
	void OnRep_ParryChance(const FGameplayAttributeData& OldParryChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EvadeChance, Category=Combat)
	FGameplayAttributeData EvadeChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag EvadeChanceTag;
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const;
	//Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Strength, Category=Attributes)
	FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag StrengthTag;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Agility, Category=Attributes)
	FGameplayAttributeData Agility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag AgilityTag;
	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Precision, Category=Attributes)
	FGameplayAttributeData Precision;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag PrecisionTag;
	UFUNCTION()
	void OnRep_Precision(const FGameplayAttributeData& OldPrecision) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Luck, Category=Attributes)
	FGameplayAttributeData Luck;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag LuckTag;
	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Constitution, Category=Attributes)
	FGameplayAttributeData Constitution;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag ConstitutionTag;
	UFUNCTION()
	void OnRep_Constitution(const FGameplayAttributeData& OldConstitution) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Endurance, Category=Attributes)
	FGameplayAttributeData Endurance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag EnduranceTag;
	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const;

	
};
