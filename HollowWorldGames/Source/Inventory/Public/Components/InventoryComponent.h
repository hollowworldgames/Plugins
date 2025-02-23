// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class IInventoryStorable;



USTRUCT(BlueprintType)
struct INVENTORY_API FInventoryItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int64 Id = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Qty = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxQty = 0;
};


USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()
	UPROPERTY()
	FInventoryItem Item;
	FInventoryItem RemoveItem();
	void AddItem(const FInventoryItem& Storable);
	void Swap(FInventorySlot& Slot);
	bool CanFit(const FInventoryItem& Storable) const;
	bool IsEmpty() const;
};



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UInventoryComponent();
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddToSlot(int Slot, FInventoryItem Item);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddToAny(FInventoryItem Item);
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void RemoveFromSlot_Server(int Slot);
	UFUNCTION(BlueprintPure, Category="Inventory")
	bool CanFit(const FInventoryItem& Item) const;
	bool CanFitInSlot(int Slot, const FInventoryItem& Item) const;
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void GetSlots(TArray<FInventoryItem>& Items) const;
	bool HasInInventory(FGameplayTag Item, int Qty) const;
	bool IsEmpty(int Slot) const;
	FInventoryItem GetSlot(int Slot) const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(EditAnywhere, Replicated, ReplicatedUsing=OnRep_Slots, BlueprintReadOnly, Category=Inventory)
	TArray<FInventorySlot> Slots;
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void AddToSlot_Server(int Slot, FInventoryItem Item);
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void AddToAny_Server(FInventoryItem Item);
	UFUNCTION()
	void OnRep_Slots(TArray<FInventorySlot>& OldSlots) const;
	UPROPERTY(EditAnywhere, Replicated, ReplicatedUsing=OnRep_SlotCount, BlueprintReadOnly, Category=Inventory)
	int SlotCount = 50;
	UFUNCTION()
	void OnRep_SlotCount(int& OldSlotCount) const;
};

