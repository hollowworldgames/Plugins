// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/PlanetoidActor.h"

#include "Data/Orbital.h"


// Sets default values
APlanetoidActor::APlanetoidActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlanetoidActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanetoidActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Planetoid)
	{
		SetActorLocation(Planetoid->GetOrbitalLocation());
		SetActorRotation(Planetoid->GetOrbitalRotation());
	}
}

void APlanetoidActor::SetPlanetoid(UPlanetoid* NewPlanetoid)
{
	Planetoid = NewPlanetoid;
	OnCreate.Broadcast(NewPlanetoid);
}

