// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/FantasyCraftingRecipe.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(IngredientTag, "Item.Ingredient", "Crafting Ingredient")

void UFantasyCraftingRecipe::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == FName("Ingredients"))
	{
		for (FFantasyCraftingRecipeIngredient Ingredient : Ingredients)
		{
			if (Ingredient.Ingredient.IsValid() && !Ingredient.Ingredient.MatchesTag(IngredientTag))
			{
				//Must be an Ingredient
				Ingredient.Ingredient = FGameplayTag();
			}
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
