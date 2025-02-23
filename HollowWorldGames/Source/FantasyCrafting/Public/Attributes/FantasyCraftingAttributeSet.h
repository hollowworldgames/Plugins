// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/CraftingAttributeSet.h"
#include "FantasyCraftingAttributeSet.generated.h"

FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ProspectingTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ProspectingExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ProspectingLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForestryTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForestryExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForestryLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FarmingTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FarmingExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FarmingLevelTag);

FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JewelerTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JewelerExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JewelerLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HerbalistTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HerbalistExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HerbalistLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CookTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CookExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CookLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlacksmithTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlacksmithExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlacksmithLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WoodWorkerTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WoodWorkerExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WoodWorkerLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LoreMasterTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LoreMasterExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LoreMasterLevelTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TailorTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TailorExperienceTag);
FANTASYCRAFTING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TailorLevelTag);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCraftingLevelNotify, FGameplayAttribute, Attribute, float, NewLevel);

UCLASS()
class FANTASYCRAFTING_API UFantasyCraftingAttributeSet : public UCraftingAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ProspectingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingProspectingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ProspectingLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ForestryExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingForestryExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, ForestryLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, FarmingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingFarmingExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, FarmingLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, JewelerExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingJewelerExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, JewelerLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, HerbalistExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingHerbalistExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, HerbalistLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, CookExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingCookExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, CookLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, BlacksmithExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingBlacksmithExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, BlacksmithLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, WoodWorkerExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingWoodWorkerExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, WoodWorkerLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, LoreMasterExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingLoreMasterExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, LoreMasterLevel);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, TailorExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, IncomingTailorExperience);
	ATTRIBUTE_ACCESSORS(UFantasyCraftingAttributeSet, TailorLevel);

	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ForestryExperience, Category=Gathering)
	FGameplayAttributeData ForestryExperience;

	UFUNCTION()
	void OnRep_ForestryExperience(const FGameplayAttributeData& OldForestryExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FGameplayAttributeData IncomingForestryExperience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FScalableFloat ForestryCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ForestryLevel, Category=Gathering)
	FGameplayAttributeData ForestryLevel;

	UFUNCTION()
	void OnRep_ForestryLevel(const FGameplayAttributeData& OldForestryLevel) const;
	//Farming
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FarmingExperience, Category=Gathering)
	FGameplayAttributeData FarmingExperience;
	
	UFUNCTION()
	void OnRep_FarmingExperience(const FGameplayAttributeData& OldFarmingExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FGameplayAttributeData IncomingFarmingExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gathering)
	FScalableFloat FarmingCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FarmingLevel, Category=Gathering)
	FGameplayAttributeData FarmingLevel;
	
	UFUNCTION()
	void OnRep_FarmingLevel(const FGameplayAttributeData& OldFarmingLevel) const;
	//crafting Skills
	
	//Jeweler - able to create sigils that imbue an item with attribute bonuses
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JewelerExperience, Category=Crafting)
	FGameplayAttributeData JewelerExperience;
	
	UFUNCTION()
	void OnRep_JewelerExperience(const FGameplayAttributeData& OldJewelerExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingJewelerExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat JewelerCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JewelerLevel, Category=Crafting)
	FGameplayAttributeData JewelerLevel;
	
	UFUNCTION()
	void OnRep_JewelerLevel(const FGameplayAttributeData& OldJewelerLevel) const;
	//Herbalist - Medicine
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HerbalistExperience, Category=Crafting)
	FGameplayAttributeData HerbalistExperience;
	
	UFUNCTION()
	void OnRep_HerbalistExperience(const FGameplayAttributeData& OldHerbalistExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingHerbalistExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat HerbalistCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HerbalistLevel, Category=Crafting)
	FGameplayAttributeData HerbalistLevel;
	
	UFUNCTION()
	void OnRep_HerbalistLevel(const FGameplayAttributeData& OldHerbalistLevel) const;
	//Cook - food
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CookExperience, Category=Crafting)
	FGameplayAttributeData CookExperience;
	
	UFUNCTION()
	void OnRep_CookExperience(const FGameplayAttributeData& OldCookExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingCookExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat CookCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CookLevel, Category=Crafting)
	FGameplayAttributeData CookLevel;
	
	UFUNCTION()
	void OnRep_CookLevel(const FGameplayAttributeData& OldCookLevel) const;
	//Blacksmith - Swords, daggers, Shields, and Armor
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlacksmithExperience, Category=Crafting)
	FGameplayAttributeData BlacksmithExperience;
	
	UFUNCTION()
	void OnRep_BlacksmithExperience(const FGameplayAttributeData& OldBlacksmithExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingBlacksmithExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat BlacksmithCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlacksmithLevel, Category=Crafting)
	FGameplayAttributeData BlacksmithLevel;
	
	UFUNCTION()
	void OnRep_BlacksmithLevel(const FGameplayAttributeData& OldBlacksmithLevel) const;
	//Wood worker - Bows, Spears, Clubs, and Maces
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WoodWorkerExperience, Category=Crafting)
	FGameplayAttributeData WoodWorkerExperience;
	
	UFUNCTION()
	void OnRep_WoodWorkerExperience(const FGameplayAttributeData& OldWoodWorkerExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingWoodWorkerExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat WoodWorkerCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WoodWorkerLevel, Category=Crafting)
	FGameplayAttributeData WoodWorkerLevel;
	
	UFUNCTION()
	void OnRep_WoodWorkerLevel(const FGameplayAttributeData& OldWoodWorkerLevel) const;
	//Lore-master - Attribute tomes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LoreMasterExperience, Category=Crafting)
	FGameplayAttributeData LoreMasterExperience;
	
	UFUNCTION()
	void OnRep_LoreMasterExperience(const FGameplayAttributeData& OldLoreMasterExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingLoreMasterExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat LoreMasterCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LoreMasterLevel, Category=Crafting)
	FGameplayAttributeData LoreMasterLevel;
	
	UFUNCTION()
	void OnRep_LoreMasterLevel(const FGameplayAttributeData& OldLoreMasterLevel) const;
	//Tailor - clothing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_TailorExperience, Category=Crafting)
	FGameplayAttributeData TailorExperience;
	
	UFUNCTION()
	void OnRep_TailorExperience(const FGameplayAttributeData& OldTailorExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FGameplayAttributeData IncomingTailorExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Crafting)
	FScalableFloat TailorCurve; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_TailorLevel, Category=Crafting)
	FGameplayAttributeData TailorLevel;
	
	UFUNCTION()
	void OnRep_TailorLevel(const FGameplayAttributeData& OldTailorLevel) const;
};
