// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "ConstructableObjectTableRow.generated.h"

USTRUCT(BlueprintType)
struct FAttributeEffect
{
	GENERATED_BODY()
public :
	UPROPERTY()
	FGameplayTag Attribute;
	UPROPERTY()
	FGameplayTag Effect;
	UPROPERTY()
	float Ratio;
};

USTRUCT(BlueprintType)
struct FNeeded
{
	GENERATED_BODY()
public :
	UPROPERTY()
	FGameplayTag Tag;
	UPROPERTY()
	float Quantity;
	UPROPERTY()
	TArray<FAttributeEffect> AttributesDesired;
};

USTRUCT(BlueprintType)
struct ECONOMY_API FConstructableObjectTableRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag ObjectName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FNeeded> Resources;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FNeeded> Materials;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FNeeded> Components;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FGameplayTag> Attributes;
};
