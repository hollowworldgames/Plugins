// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"

#include "Interfaces/InventoryStorable.h"
#include "Net/UnrealNetwork.h"


TObjectPtr<UObject> FInventorySlot::RemoveItem()
{
	if(Stack.Num() > 0)
	{
		TObjectPtr<UObject> Out = Stack[0];
		Stack.RemoveAt(0);
		return Out;
	}
	return nullptr;
}

void FInventorySlot::AddItem(TObjectPtr<UObject> Storable)
{
	if(Storable->Implements<UInventoryStorable>())
	{
		Stack.Add(Storable);
	}
}

void FInventorySlot::Swap(FInventorySlot& Slot)
{
	TArray<TObjectPtr<UObject>> Temp = Stack;
	Stack = Slot.Stack;
	Slot.Stack = Temp;
}

bool FInventorySlot::CanFit(TObjectPtr<UObject> Storable)
{
	if(Storable->Implements<UInventoryStorable>())
	{
		TScriptInterface<IInventoryStorable> Store = Storable;
		if(ensure(Store))
		{
			
		}
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

void UInventoryComponent::AddToAny_Server_Implementation(UObject * Item)
{
}

void UInventoryComponent::AddToSlot_Server_Implementation(int Slot,UObject * Item)
{
}


void UInventoryComponent::RemoveFromSlot_Server_Implementation(int Slot)
{
	if(Slots.Num() > Slot)
	{
		Slots[Slot].RemoveItem();
	}
}
