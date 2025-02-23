//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/FantasyPlayerCharacter.h"

#include "UtilityStatics.h"
#include "Components/MappedInputComponent.h"
#include "Player/FantasyPlayerState.h"


// Sets default values
AFantasyPlayerCharacter::AFantasyPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CharacterInputComponent = CreateDefaultSubobject<UCharacterInputComponent>(TEXT("InputComponent"));
}

// Called when the game starts or when spawned
void AFantasyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<FInventoryItem> AFantasyPlayerCharacter::GetInventory() const
{
	TArray<FInventoryItem> Items;
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			InventoryComponent->GetSlots(Items);
		}
	}
	return Items;
}

bool AFantasyPlayerCharacter::HasInInventory(FGameplayTag Item, int Qty) const
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			return InventoryComponent->HasInInventory(Item, Qty);
		}
	}
	return false;
}

void AFantasyPlayerCharacter::Store(FInventoryItem Item)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			InventoryComponent->AddToAny(Item);
		}
	}
}

void AFantasyPlayerCharacter::Store(FInventoryItem Item, int Slot)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			InventoryComponent->AddToSlot(Slot, Item);
		}
	}
}

void AFantasyPlayerCharacter::Swap(int Source, int Target)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			
		}
	}
}

void AFantasyPlayerCharacter::Combine(int Source, int Target)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			if (InventoryComponent->CanFitInSlot(Target, GetItem(Source)))
			{
				InventoryComponent->AddToSlot(Target, GetItem(Source));
				InventoryComponent->RemoveFromSlot_Server(Source);
			}
		}
	}
}

FInventoryItem AFantasyPlayerCharacter::Remove(int Slot)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			const FInventoryItem Item = InventoryComponent->GetSlot(Slot);
			InventoryComponent->RemoveFromSlot_Server(Slot);
			return Item;
		}
	}
	return FInventoryItem();
}

FInventoryItem AFantasyPlayerCharacter::GetItem(int Slot)
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			return InventoryComponent->GetSlot(Slot);
		}
	}
	return FInventoryItem();
}

bool AFantasyPlayerCharacter::IsEmpty(int Slot) const
{
	if (IsValid(GetPlayerState()))
	{
		UInventoryComponent * InventoryComponent = GetPlayerState()->GetComponentByClass<UInventoryComponent>();
		if (IsValidEnsure(InventoryComponent))
		{
			return InventoryComponent->IsEmpty(Slot);
		}
	}
	return true;
}

// Called to bind functionality to input
void AFantasyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (IsValidEnsure(CharacterInputComponent) && IsValidEnsure(PlayerInputComponent))
	{
		CharacterInputComponent->InitializePlayerInput(Cast<UMappedInputComponent>(PlayerInputComponent));
	}
}


void AFantasyPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	AFantasyPlayerState * State = GetPlayerState<AFantasyPlayerState>();
	if (IsValidEnsure(State))
	{
		State->PlayerAlive();
	}
}

