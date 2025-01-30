//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.
#include "Characters/FantasyExperienceCharacter.h"


// Sets default values
AFantasyExperienceCharacter::AFantasyExperienceCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFantasyExperienceCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyExperienceCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


