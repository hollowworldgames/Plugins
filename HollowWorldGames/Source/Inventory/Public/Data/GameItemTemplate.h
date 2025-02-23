// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "Engine/DataAsset.h"
#include "Interfaces/InventoryStorable.h"
#include "Variables/IntVariableAsset.h"
#include "GameItemTemplate.generated.h"

INVENTORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemTag);

UCLASS(BlueprintType, Blueprintable)
class INVENTORY_API UGameItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGuid Guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StackLimit = 1;
};

UCLASS(BlueprintType)
class INVENTORY_API UGameItemTemplate : public UDataAsset
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	virtual UGameItem * CreateInstance(UObject* Outer) const;
	UFUNCTION(BlueprintPure)
	virtual UGameItem * GetDefaultInstance() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UIntVariableAsset> StackLimit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameItem> ItemTemplate;
};
