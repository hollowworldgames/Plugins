// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpaceCraft/Stations/StationPawn.h"

// Sets default values
AStationPawn::AStationPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

