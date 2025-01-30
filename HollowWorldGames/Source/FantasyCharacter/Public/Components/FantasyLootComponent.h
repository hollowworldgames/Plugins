// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FantasyLooterComponent.h"
#include "Components/ActorComponent.h"
#include "FantasyLootComponent.generated.h"


class IInventoryStorable;
class UFantasyLootTable;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYCHARACTER_API UFantasyLootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyLootComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	bool IsLootable() const;
	void Loot(UFantasyLooterComponent* FantasyLooterComponent);
	void Loot(TScriptInterface<IInventoryStorable> Item, UFantasyLooterComponent* FantasyLooterComponent);
	void GenerateLoot();
	TArray<TScriptInterface<IInventoryStorable>> GetLoot() { return AvailableLoot;}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
	bool Lootable = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot")
	TObjectPtr<UFantasyLootTable> LootTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
	TArray<TScriptInterface<IInventoryStorable>> AvailableLoot;
};

