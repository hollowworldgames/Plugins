// Fill out your copyright notice in the Description page of Project Settings.


#include "Stations/TacticalStationPawn.h"


// Sets default values
ATacticalStationPawn::ATacticalStationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATacticalStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATacticalStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATacticalStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

