// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AttributeDescriptionData.generated.h"

USTRUCT(BlueprintType)
struct GAMEPLAY_API FAttributeDescription
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
};


UCLASS()
class GAMEPLAY_API UAttributeDescriptionData : public UDataAsset
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure, Category = "Attribute Data")
	FName GetAttributeName(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure, Category = "Attribute Data")
	FString GetAttributeDescription(FGameplayTag Tag) const;
protected :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AttributeDescription")
	TMap<FGameplayTag, FAttributeDescription> AttributeData;
};
