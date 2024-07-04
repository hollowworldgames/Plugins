// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Stations/UniversalStationPawn.h"


// Sets default values
AUniversalStationPawn::AUniversalStationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUniversalStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUniversalStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AUniversalStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

