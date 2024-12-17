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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Resources)
	FGameplayTag ResourceName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Resources)
	float UnitsRequired;
};

USTRUCT(BlueprintType)
struct ECONOMY_API FRefinedMaterialTableRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	FGameplayTag MaterialName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = Settings)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
	TArray<FMineableResourceNeeded> Resources;
};
