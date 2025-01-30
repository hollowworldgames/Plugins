// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FantasyLooterComponent.h"

#include "UtilityStatics.h"
#include "Components/FantasyLootComponent.h"
#include "Components/InventoryComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerState.h"
#include "Variables/IntVariableAsset.h"


// Sets default values for this component's properties
UFantasyLooterComponent::UFantasyLooterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyLooterComponent::Loot(UFantasyLootComponent* LootComponent)
{
	if (LootComponent)
	{
		LootComponent->Loot(this);
		OnItemLooted.Broadcast(this, LootComponent);
	}
}

void UFantasyLooterComponent::LootAll()
{
	for (UFantasyLootComponent * Loot : AvailableLoot)
	{
		Loot->Loot(this);
	}
}

void UFantasyLooterComponent::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		UFantasyLootComponent * LootComponent = OtherActor->GetComponentByClass<UFantasyLootComponent>();
		if (IsValid(LootComponent) && LootComponent->IsLootable())
		{
			if (AutoLoot)
			{
				AvailableLoot.AddUnique(LootComponent);
				LootAll();
			}
			else
			{
				AvailableLoot.AddUnique(LootComponent);
				OnLootAvailable.Broadcast(this, LootComponent);
			}
		}
	}
}


void UFantasyLooterComponent::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		UFantasyLootComponent * LootComponent = OtherActor->GetComponentByClass<UFantasyLootComponent>();
		if (IsValid(LootComponent))
		{
			AvailableLoot.Remove(LootComponent);
			if (AvailableLoot.Num() == 0)
			{
				OnLootUnavailable.Broadcast(this, LootComponent);
			}
		}
	}
}

// Called when the game starts
void UFantasyLooterComponent::BeginPlay()
{
	Super::BeginPlay();
	BindOverlaps();
}

void UFantasyLooterComponent::UnbindOverlaps()
{
	if (const APlayerState * PlayerState = GetOwner<APlayerState>())
	{
		ACharacter * Character = PlayerState->GetPawn<ACharacter>();
		if (IsValidEnsure(Character))
		{
			Character->GetMesh()->OnComponentBeginOverlap.RemoveDynamic(this, &UFantasyLooterComponent::BeginOverlap);
			Character->GetMesh()->OnComponentEndOverlap.RemoveDynamic(this, &UFantasyLooterComponent::EndOverlap);
		}
	}
}

void UFantasyLooterComponent::BindOverlaps()
{
	if (const APlayerState * PlayerState = GetOwner<APlayerState>())
	{
		ACharacter * Character = PlayerState->GetPawn<ACharacter>();
		if (IsValidEnsure(Character))
		{
			Character->GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &UFantasyLooterComponent::BeginOverlap);
			Character->GetMesh()->OnComponentEndOverlap.AddDynamic(this, &UFantasyLooterComponent::EndOverlap);
		}
	}
}

void UFantasyLooterComponent::LootItem(const TScriptInterface<IInventoryStorable>& Item)
{
	if (!Item)
		return;
	switch (LootMode)
	{
	case ELootMode::ELootMode_LootInventory :
		{
			if (LootItems.Num() < MaxCapacity->GetValue())
			{
				LootItems.Add(Item);
			}
			else
			{
				//send error Message
			}
			break;
		}
	case ELootMode::ELootMode_DirectToInventory :
		{
			if (CanTransferToInventory(Item))
			{
				TransferToInventory(Item);
			}
			else
			{
				//send error message
			}
			break;
		}
	}
}

void UFantasyLooterComponent::TransferToInventory(const TScriptInterface<IInventoryStorable>& Item)
{
	if (CanTransferToInventory(Item))
	{
		LootItems.Remove(Item);
		UInventoryComponent * InventoryComponent = GetOwner()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			FInventoryItem ItemToAdd;
			ItemToAdd.ItemId = Item->GetItemId();
			ItemToAdd.Qty = Item->GetQty();
			InventoryComponent->AddToAny_Server(ItemToAdd);
		}
	}
	else
	{
		//Send Error Message
	}
}

bool UFantasyLooterComponent::CanTransferToInventory(const TScriptInterface<IInventoryStorable>& Item) const
{
	UInventoryComponent * InventoryComponent = GetOwner()->GetComponentByClass<UInventoryComponent>();
	if (IsValidEnsure(InventoryComponent))
	{
		return InventoryComponent->CanFit(Item.GetObject());
	}
	return false;
}

void UFantasyLooterComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UnbindOverlaps();
}
