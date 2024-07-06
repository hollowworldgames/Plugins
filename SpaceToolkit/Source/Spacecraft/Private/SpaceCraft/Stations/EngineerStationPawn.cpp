// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Stations/EngineerStationPawn.h"


// Sets default values
AEngineerStationPawn::AEngineerStationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEngineerStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEngineerStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEngineerStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

