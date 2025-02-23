// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/FantasyPlayerMountCharacter.h"

#include "Components/FantasyMountInputComponent.h"
#include "Components/MappedInputComponent.h"


// Sets default values
AFantasyPlayerMountCharacter::AFantasyPlayerMountCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MountInputComponent = CreateDefaultSubobject<UFantasyMountInputComponent>(TEXT("FantasyMountInput"));
}

// Called when the game starts or when spawned
void AFantasyPlayerMountCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AFantasyPlayerMountCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	MountInputComponent->InitializePlayerInput(Cast<UMappedInputComponent>(PlayerInputComponent));
}

