// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "NPC/FantasyQuestGiverCharacter.h"


// Sets default values
AFantasyQuestGiverCharacter::AFantasyQuestGiverCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	QuestComponent = CreateDefaultSubobject<UQuestGiverComponent>("QuestGiverComponent");
}

// Called when the game starts or when spawned
void AFantasyQuestGiverCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyQuestGiverCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
