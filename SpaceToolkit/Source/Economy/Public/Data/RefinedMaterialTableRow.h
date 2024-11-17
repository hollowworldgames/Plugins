// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "RefinedMaterialTableRow.generated.h"

USTRUCT(BlueprintType)
struct FMineableResourceNeeded
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag ResourceName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float UnitsRequired;
};

USTRUCT(BlueprintType)
struct ECONOMY_API FRefinedMaterialTableRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag MaterialName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMineableResourceNeeded> Resources;
};
