// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/XRHandActor.h"


// Sets default values
AXRHandActor::AXRHandActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AXRHandActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXRHandActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

