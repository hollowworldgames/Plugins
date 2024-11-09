// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/LocationActor.h"


// Sets default values
ALocationActor::ALocationActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALocationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALocationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

