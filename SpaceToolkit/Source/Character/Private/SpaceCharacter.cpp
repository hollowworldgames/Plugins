// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCharacter.h"


// Sets default values
ASpaceCharacter::ASpaceCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ASpaceCharacter::GetAbilitySystemComponent() const
{
	ensureMsgf(false,TEXT("SpaceCharacter Not Overriden"));
	return nullptr;
}

