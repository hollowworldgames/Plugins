// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FantasyCombatCharacter.h"
#include "Components/CharacterInputComponent.h"
#include "Interfaces/InventoryContainer.h"
#include "FantasyPlayerCharacter.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerCharacter : public AFantasyCombatCharacter, public IInventoryContainer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyPlayerCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual TArray<FInventoryItem> GetInventory() const override;
	virtual bool HasInInventory(FGameplayTag Item, int Qty) const override;
	virtual void Store(FInventoryItem Item) override;
	virtual void Store(FInventoryItem Item, int Slot) override;
	virtual void Swap(int Source, int Target) override;
	virtual void Combine(int Source, int Target) override;
	virtual FInventoryItem Remove(int Slot) override;
	virtual FInventoryItem GetItem(int Slot) override;
	virtual bool IsEmpty(int Slot) const override;
protected:
	virtual void OnRep_PlayerState() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UCharacterInputComponent> CharacterInputComponent;
};
