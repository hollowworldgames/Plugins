// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/SpaceCraftSkeletalMeshActor.h"


// Sets default values
ASpaceCraftSkeletalMeshActor::ASpaceCraftSkeletalMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(Root = CreateDefaultSubobject<USkeletalMeshComponent>("Root"));
}

// Called when the game starts or when spawned
void ASpaceCraftSkeletalMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCraftSkeletalMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

