// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "Engine/DataAsset.h"
#include "FantasyCraftingRecipe.generated.h"

struct FGameplayAttribute;
enum class EFantasyCraftingIngredientQuality : uint8;

USTRUCT(BlueprintType)
struct FFantasyCraftingRecipeIngredient
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FGameplayTag Ingredient;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int QtyNeeded = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	EFantasyCraftingIngredientQuality Quality;
};

UE_DECLARE_GAMEPLAY_TAG_EXTERN(IngredientTag);


UCLASS()
class FANTASYCRAFTING_API UFantasyCraftingRecipe : public UDataAsset
{
	GENERATED_BODY()
public :
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FName RecipeName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FString RecipeDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FGameplayTag RecipeTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	FGameplayTag CraftingAttributeRequired;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	float SkillLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ingredients")
	TArray<FFantasyCraftingRecipeIngredient> Ingredients;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FGameplayTag OutputItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int OutputQty = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Station")
	FGameplayTag StationRequiredTag;
};
