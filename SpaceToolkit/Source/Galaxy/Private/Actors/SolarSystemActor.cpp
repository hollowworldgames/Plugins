﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/SolarSystemActor.h"


// Sets default values
ASolarSystemActor::ASolarSystemActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASolarSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolarSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

