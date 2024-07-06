// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Stations/GunnerStationPawn.h"


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

