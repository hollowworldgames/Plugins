// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "InputMapDefaultsData.generated.h"



USTRUCT(BlueprintType)
struct FInputMapping
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag InputTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag OutputTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Invert = false;
};

UCLASS()
class INPUTMAPPING_API UInputMapDefaultsData : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TArray<FInputMapping> Mappings;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FString InputGroup;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FGameplayTagContainer OutputTags;
};
