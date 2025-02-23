//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.
#include "Characters/FantasyCharacterBase.h"


// Sets default values
AFantasyCharacterBase::AFantasyCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFantasyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AFantasyCharacterBase::GetSpeed() const
{
	return GetVelocity().Length();
}

float AFantasyCharacterBase::GetDirection() const
{
	return 0;
}

float AFantasyCharacterBase::GetTurn() const
{
	return 0;
}

bool AFantasyCharacterBase::IsAlive() const
{
	return true;
}


