// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KnownItemDatabaseComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORY_API UKnownItemDatabaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UKnownItemDatabaseComponent();
	UObject * GetItem(int64 ItemId);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Items")
	TObjectPtr<UDataTable> ItemTemplate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Items")
	TMap<int64, TObjectPtr<UObject>> Items;
};
