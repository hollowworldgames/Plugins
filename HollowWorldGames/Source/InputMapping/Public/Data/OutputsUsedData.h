// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "OutputsUsedData.generated.h"

USTRUCT(BlueprintType)
struct FOutputUsed
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OutputsUsedData")
	FGameplayTag Output;
};


UCLASS(BlueprintType)
class INPUTMAPPING_API UOutputsUsedData : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TArray<FOutputUsed> Outputs;
};
