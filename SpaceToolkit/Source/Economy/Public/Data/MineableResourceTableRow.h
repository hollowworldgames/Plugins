// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "MineableResourceTableRow.generated.h"

UENUM()
enum class EResourceRarity : uint8
{
	EResourceRarity_Common UMETA(DisplayName = "Common"),
	EResourceRarity_Uncommon UMETA(DisplayName = "Uncommon"),
	EResourceRarity_Rare UMETA(DisplayName = "Rare"),
	EResourceRarity_Exotic UMETA(DisplayName = "Exotic"),
	EResourceRarity_Legendary UMETA(DisplayName = "Legendary"),
};

USTRUCT(BlueprintType)
struct ECONOMY_API FMineableResourceTableRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ResourceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EResourceRarity Rarity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ResourceClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ResourceCategory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, float> Attributes;
};
