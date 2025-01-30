// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameItemTemplate.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGameItem : public UObject
{
	GENERATED_BODY()
public:
	
};

UCLASS(BlueprintType)
class INVENTORY_API UGameItemTemplate : public UDataAsset
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	UGameItem * CreateInstance(UObject* Outer) const;
	UFUNCTION(BlueprintPure)
	UGameItem * GetDefaultInstance() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int64 ItemTemplateId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameItem> ItemTemplate;
};
