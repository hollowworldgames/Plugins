// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/InventoryStorable.h"
#include "FantasyLooterComponent.generated.h"

class UIntVariableAsset;
class UFantasyLootComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLootNotify, UFantasyLooterComponent*, LootComponent, UFantasyLootComponent*, AvailableComponent);

UENUM(BlueprintType)
enum class ELootMode : uint8
{
	ELootMode_LootInventory,
	ELootMode_DirectToInventory,
};

class UFantasyLootComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYCHARACTER_API UFantasyLooterComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UFantasyLooterComponent();
	UFUNCTION(BlueprintCallable)
	void Loot(UFantasyLootComponent* LootComponent);
	UFUNCTION(BlueprintCallable)
	void LootAll();
	void UnbindOverlaps();
	void BindOverlaps();
	void LootItem(const TScriptInterface<IInventoryStorable>& Item);
	void TransferToInventory(const TScriptInterface<IInventoryStorable>& Item);
	bool CanTransferToInventory(const TScriptInterface<IInventoryStorable>& Item) const;
protected:
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Status)
	TArray<TObjectPtr<UFantasyLootComponent>> AvailableLoot;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FLootNotify OnLootAvailable;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FLootNotify OnLootUnavailable;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FLootNotify OnItemLooted;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	ELootMode LootMode = ELootMode::ELootMode_LootInventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	bool AutoLoot = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	TObjectPtr<UIntVariableAsset> MaxCapacity;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Loot)
	TArray<TScriptInterface<IInventoryStorable>> LootItems;
};
