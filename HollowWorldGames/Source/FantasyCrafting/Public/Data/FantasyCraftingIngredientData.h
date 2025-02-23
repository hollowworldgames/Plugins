// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GameItemTemplate.h"
#include "FantasyCraftingIngredientData.generated.h"


UENUM(BlueprintType)
enum class EFantasyCraftingIngredientQuality : uint8
{
	EQuality_Common UMETA(DisplayName = "Common"),
	EQuality_Uncommon UMETA(DisplayName = "Uncommon"),
	EQuality_Rare UMETA(DisplayName = "Rare"),
	EQuality_Epic UMETA(DisplayName = "Epic"),
	EQuality_Legendary UMETA(DisplayName = "Legendary"),
};

UCLASS()
class FANTASYCRAFTING_API UFantasyCraftingIngredientData : public UGameItemTemplate
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	EFantasyCraftingIngredientQuality Quality;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int Tier = 0;
};
