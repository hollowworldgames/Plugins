// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Stations/GunnerStationPawn.h"


// Sets default values
AGunnerStationPawn::AGunnerStationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGunnerStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunnerStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGunnerStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

