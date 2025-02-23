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
			Item.ItemId = FGameplayTag();
			Item.Id = 0;
			Item.MaxQty = 0;
			Item.Qty = 0;
		}
		return RemovedItem;
	}
	return FInventoryItem();
}

void FInventorySlot::AddItem(const FInventoryItem& Storable)
{
	if (IsEmpty())
	{
		Item.ItemId = Storable.ItemId;
		Item.Id = Storable.Id;
		Item.Qty = Storable.Qty;
		Item.MaxQty = Storable.MaxQty;
	}
	else
	{
		if(Storable.ItemId.MatchesTagExact(Item.ItemId))
		{
			Item.Qty += Storable.Qty;
		}
	}
}

void FInventorySlot::Swap(FInventorySlot& Slot)
{
	FInventoryItem Temp = Item;
	Item = Slot.Item;
	Slot.Item = Temp;
}

bool FInventorySlot::CanFit(const FInventoryItem& Storable) const
{
	if (IsEmpty())
	{
		return true;
	}
	if(Item.ItemId.MatchesTagExact(Storable.ItemId) && Item.Qty + Storable.Qty < Item.MaxQty)
	{
		return true;
	}
	return false;
}

bool FInventorySlot::IsEmpty() const
{
	if (Item.ItemId.IsValid())
	{
		return false;
	}
	return true;
}

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventoryComponent::AddToSlot(const int Slot, const FInventoryItem Item)
{
	AddToSlot_Server(Slot, Item);
}

void UInventoryComponent::AddToAny(const FInventoryItem Item)
{
	AddToAny_Server(Item);
}

bool UInventoryComponent::CanFit(const FInventoryItem& Item) const
{
	for (auto slot : Slots)
	{
		if (slot.CanFit(Item))
		{
			return true;
		}
	}
	return false;
}

bool UInventoryComponent::CanFitInSlot(int Slot, const FInventoryItem& Item) const
{
	if (Slot < Slots.Num())
	{
		return Slots[Slot].CanFit(Item);
	}
	return false;
}

void UInventoryComponent::GetSlots(TArray<FInventoryItem>& Items) const
{
	for (auto Slot : Slots)
	{
		Items.Add(Slot.Item);
	}
}

bool UInventoryComponent::HasInInventory(const FGameplayTag Item, const int Qty) const
{
	int QtyInInventory = 0;
	for (auto slot : Slots)
	{
		if (slot.Item.ItemId.MatchesTagExact(Item))
		{
			QtyInInventory += slot.Item.Qty;
		}
	}
	return QtyInInventory >= Qty;
}

bool UInventoryComponent::IsEmpty(const int Slot) const
{
	if (Slot < Slots.Num())
	{
		return Slots[Slot].IsEmpty();
	}
	return false;
}


FInventoryItem UInventoryComponent::GetSlot(int Slot) const
{
	if (Slot < Slots.Num())
	{
		return Slots[Slot].Item;
	}
	return FInventoryItem();
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

void UInventoryComponent::OnRep_SlotCount(int& OldSlotCount) const
{
	
}

void UInventoryComponent::AddToAny_Server_Implementation(FInventoryItem Item)
{
	for (auto slot : Slots)
	{
		if (slot.CanFit(Item))
		{
			slot.AddItem(Item);
		}
	}
}

void UInventoryComponent::AddToSlot_Server_Implementation(int Slot, FInventoryItem Item)
{
	if (Slot < Slots.Num() && Slots[Slot].CanFit(Item))
	{
		Slots[Slot].AddItem(Item);
	}
}


void UInventoryComponent::RemoveFromSlot_Server_Implementation(int Slot)
{
	if(Slots.Num() > Slot)
	{
		Slots[Slot].RemoveItem();
	}
}
