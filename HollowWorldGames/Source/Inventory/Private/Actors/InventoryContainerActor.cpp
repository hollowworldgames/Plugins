// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/InventoryContainerActor.h"


// Sets default values
AInventoryContainerActor::AInventoryContainerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInventoryContainerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryContainerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInventoryContainerActor::OnInteraction(TScriptInterface<IInteractor> interactor)
{
	
}

