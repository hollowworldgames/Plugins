// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/InteractableComponent.h"
#include "GameFramework/Actor.h"
#include "InventoryContainerActor.generated.h"

class UInventoryComponent;

UCLASS()
class INVENTORY_API AInventoryContainerActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInventoryContainerActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnInteraction(TScriptInterface<IInteractor> interactor);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UInventoryComponent> InventoryComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UInteractableComponent> InteractableComponent;
};
