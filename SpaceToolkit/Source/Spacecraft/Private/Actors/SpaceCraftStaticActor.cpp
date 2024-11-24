// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/SpaceCraftStaticActor.h"


// Sets default values
ASpaceCraftStaticActor::ASpaceCraftStaticActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root")));
}

// Called when the game starts or when spawned
void ASpaceCraftStaticActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCraftStaticActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

