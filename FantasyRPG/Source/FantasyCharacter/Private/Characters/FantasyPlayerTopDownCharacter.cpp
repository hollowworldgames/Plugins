// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Characters/FantasyPlayerTopDownCharacter.h"


// Sets default values
AFantasyPlayerTopDownCharacter::AFantasyPlayerTopDownCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFantasyPlayerTopDownCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyPlayerTopDownCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyPlayerTopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

