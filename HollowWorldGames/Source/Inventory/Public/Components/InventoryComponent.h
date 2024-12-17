// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class IInventoryStorable;

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<TObjectPtr<UObject>> Stack;
	TObjectPtr<UObject> RemoveItem();
	void AddItem(TObjectPtr<UObject> Storable);
	void Swap(FInventorySlot& Slot);
	bool CanFit(TObjectPtr<UObject> Storable);
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void AddToSlot_Server(int Slot,UObject* Item);
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void AddToAny_Server(UObject* Item);
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory")
	void RemoveFromSlot_Server(int Slot);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(EditAnywhere, Replicated, ReplicatedUsing=OnRep_Slots, BlueprintReadOnly, Category=Inventory)
	TArray<FInventorySlot> Slots;
	UFUNCTION()
	void OnRep_Slots(TArray<FInventorySlot>& OldSlots) const;
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadOnly, Category=Inventory)
	int SlotCount = 50;
};
