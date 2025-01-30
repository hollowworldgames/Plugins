// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "FantasyCraftingAttributeSet.generated.h"

FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ProspectingExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ProspectingLevelTag);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCraftingLevelNotify, float, NewLevel);

UCLASS()
class FANTASYCRAFTING_API UFantasyCraftingAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ProspectingExperience);
	ATTRIBUTE_TAG_ACCESSOR(UFantasyCraftingAttributeSet, ProspectingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingProspectingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ProspectingLevel);
	ATTRIBUTE_TAG_ACCESSOR(UFantasyCraftingAttributeSet, ProspectingLevel);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FCraftingLevelNotify OnProspectingLevel;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//Gathering Skills
	//Prospecting
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ProspectingExperience, Category=Gathering)
	FGameplayAttributeData ProspectingExperience;
	
	UFUNCTION()
	void OnRep_ProspectingExperience(const FGameplayAttributeData& OldProspectingExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FGameplayAttributeData IncomingProspectingExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FScalableFloat ProspectingCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ProspectingLevel, Category=Gathering)
	FGameplayAttributeData ProspectingLevel;
	
	UFUNCTION()
	void OnRep_ProspectingLevel(const FGameplayAttributeData& OldProspectingLevel) const;
	//Forestry
	
	//Farming
	
	//Tanner

	//crafting Skills
	
	//Alchemist - able to create sigils that imbue an item with attribute bonuses

	//Herbalist - Medicine

	//Cook - food

	//Blacksmith - Swords, daggers, Shields, and Armor

	//Wood worker - Bows, Spears, Clubs, and Maces

	//Lore-master - Attribute tomes

	//Tailor - clothing

	//Tinker - Jewelry
};
