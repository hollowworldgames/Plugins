// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/AsteroidFieldActor.h"


// Sets default values
AAsteroidFieldActor::AAsteroidFieldActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsteroidFieldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroidFieldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

