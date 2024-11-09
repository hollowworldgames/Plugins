// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/GalaxyActor.h"


// Sets default values
AGalaxyActor::AGalaxyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGalaxyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGalaxyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

