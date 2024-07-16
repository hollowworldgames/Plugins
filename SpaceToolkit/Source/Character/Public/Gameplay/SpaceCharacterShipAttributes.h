// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "SpaceCharacterShipAttributes.generated.h"

class USpaceCharacterAttributes;
/**
 * 
 */
UCLASS()
class CHARACTER_API USpaceCharacterShipAttributes : public UAttributeSet
{
	GENERATED_BODY()
public:
	ATTRIBUTE_ACCESSORS(USpaceCharacterShipAttributes, HullHealthBoost);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterShipAttributes, HullHealthBoost);
	ATTRIBUTE_ACCESSORS(USpaceCharacterShipAttributes, HullPhysicalMitigationBoost);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterShipAttributes, HullPhysicalMitigationBoost);
	ATTRIBUTE_ACCESSORS(USpaceCharacterShipAttributes, HullEnergyMitigationBoost);
	ATTRIBUTE_TAG_ACCESSOR(USpaceCharacterShipAttributes, HullEnergyMitigationBoost);
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	//Hull
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullHealthBoost, Category=Health)
	FGameplayAttributeData HullHealthBoost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HullHealthBoostTag;
	UFUNCTION()
	void OnRep_HullHealthBoost(const FGameplayAttributeData& OldHullHealthBoost) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullPhysicalMitigationBoost, Category=Health)
	FGameplayAttributeData HullPhysicalMitigationBoost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HullPhysicalMitigationBoostTag;
	UFUNCTION()
	void OnRep_HullPhysicalMitigationBoost(const FGameplayAttributeData& OldHullPhysicalMitigationBoost) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullEnergyMitigationBoost, Category=Health)
	FGameplayAttributeData HullEnergyMitigationBoost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HullEnergyMitigationBoostTag;
	UFUNCTION()
	void OnRep_HullEnergyMitigationBoost(const FGameplayAttributeData& OldHullEnergyMitigationBoost) const;
};
