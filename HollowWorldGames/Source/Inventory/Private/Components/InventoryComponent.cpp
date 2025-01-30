// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"

#include "Interfaces/InventoryStorable.h"
#include "Net/UnrealNetwork.h"


FInventoryItem FInventorySlot::RemoveItem()
{
	if(Item.Qty > 0)
	{
		FInventoryItem RemovedItem;
		RemovedItem.Qty = 1;
		RemovedItem.ItemId = Item.ItemId;
		Item.Qty--;
		if (Item.Qty < 1)
		{
			Item.ItemId = 0;
			Item.MaxQty = 0;
			Item.Qty = 0;
		}
		return RemovedItem;
	}
	return FInventoryItem();
}

void FInventorySlot::AddItem(FInventoryItem Storable)
{
	if(Storable.ItemId == Item.ItemId)
	{
		Item.Qty += Storable.Qty;
	}
}

void FInventorySlot::Swap(FInventorySlot& Slot)
{
	FInventoryItem Temp = Item;
	Item = Slot.Item;
	Slot.Item = Temp;
}

bool FInventorySlot::CanFit(const FInventoryItem Storable)
{
	if(Item.ItemId == Storable.ItemId && Item.Qty + Storable.Qty < Item.MaxQty)
	{
		Item.Qty += Storable.Qty;
	}
	return false;
}

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UInventoryComponent::CanFit(UObject* Item)
{
	return false;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UInventoryComponent, Slots, COND_OwnerOnly, REPNOTIFY_Always);
}

void UInventoryComponent::OnRep_Slots(TArray<FInventorySlot>& OldSlots) const
{
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddToAny_Server_Implementation(FInventoryItem Item)
{
}

void UInventoryComponent::AddToSlot_Server_Implementation(int Slot, FInventoryItem Item)
{
}


void UInventoryComponent::RemoveFromSlot_Server_Implementation(int Slot)
{
	if(Slots.Num() > Slot)
	{
		Slots[Slot].RemoveItem();
	}
}
