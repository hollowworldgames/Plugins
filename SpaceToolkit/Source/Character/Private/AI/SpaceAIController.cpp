// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SpaceAIController.h"


// Sets default values
ASpaceAIController::ASpaceAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

