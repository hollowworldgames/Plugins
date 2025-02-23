// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "InventoryStorableItemRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct INVENTORY_API FInventoryStorableItemRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	FGameplayTag ItemTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	TObjectPtr<UTexture> Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int StackLimit = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<UObject> ObjectClass;
};
