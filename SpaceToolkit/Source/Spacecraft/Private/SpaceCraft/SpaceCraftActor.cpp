// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SpaceCraft/SpaceCraftActor.h"

// Sets default values
ASpaceCraftActor::ASpaceCraftActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceCraftActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCraftActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

