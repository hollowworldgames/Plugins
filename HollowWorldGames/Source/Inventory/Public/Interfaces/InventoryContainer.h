// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/InventoryComponent.h"
#include "UObject/Interface.h"
#include "InventoryContainer.generated.h"

class IInventoryStorable;
// This class does not need to be modified.
UINTERFACE(BlueprintType, NotBlueprintable)
class UInventoryContainer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_API IInventoryContainer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Blueprint Functions
	UFUNCTION(BlueprintCallable, Category = "Inventory", meta = (displayName = "Get Inventory"))
	virtual TArray<FInventoryItem> GetInventory_k2() const { return GetInventory(); }
	UFUNCTION(BlueprintCallable, Category = "Inventory", meta = (displayName = "Has In Inventory"))
	virtual bool HasInInventory_K2(const FGameplayTag Item, const int Qty) const { return HasInInventory(Item, Qty); }
	UFUNCTION(BlueprintCallable, Category = "Inventory", meta = (displayName = "Store In Inventory"))
	virtual void Store_K2(const FInventoryItem Item) {  Store(Item); }
	UFUNCTION(BlueprintCallable, Category = "Inventory", meta = (displayName = "Store In Inventory Slot"))
	virtual void StoreInSlot_K2(const FInventoryItem Item, const int Slot) {  Store(Item, Slot); }
	UFUNCTION(BlueprintCallable, Category = "Inventory", meta = (displayName = "Swap Inventory Slots"))
	virtual void Swap_K2(const int Source, const int Target) { Swap(Source, Target); }
	//C++ Functions
	virtual TArray<FInventoryItem> GetInventory() const = 0;
	virtual bool HasInInventory(FGameplayTag Item, int Qty) const = 0;
	virtual void Store(FInventoryItem Item) = 0;
	virtual void Store(FInventoryItem Item, int Slot) = 0;
	virtual void Swap(int Source, int Target) = 0;
	virtual void Combine(int Source, int Target) = 0;
	virtual FInventoryItem Remove(int Slot) = 0;
	virtual FInventoryItem GetItem(int Slot) = 0;
	virtual bool IsEmpty(int Slot) const = 0;
};
