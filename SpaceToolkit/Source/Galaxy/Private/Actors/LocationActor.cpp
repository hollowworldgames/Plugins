// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/LocationActor.h"

#include "Actors/AsteroidActor.h"
#include "Actors/AsteroidFieldActor.h"
#include "Actors/CometActor.h"
#include "Actors/PlanetoidActor.h"
#include "Data/Location.h"
#include "Data/LocationClasses.h"
#include "Data/Orbital.h"


// Sets default values
ALocationActor::ALocationActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALocationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALocationActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for(const auto Spawn : Spawns)
	{
		Spawn.Value->Destroy();
	}
	Spawns.Empty();
}

// Called every frame
void ALocationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALocationActor::SetLocation(ULocation * NewLocation)
{
	Location = NewLocation;
	switch(Location->GetLocationType())
	{
	case ELocationType::ELocationType_Comet :
		{
			AddComet();
			break;
		}
	case ELocationType::ELocationType_AsteroidCluster:
		{
			AddAsteroidField();
			break;
		}
	default: break ;
	}
	for(TObjectPtr<UOrbital> Orbital : Location->GetOrbitals())
	{
		switch(Orbital->GetOrbitalType())
		{
		case EOrbitalType::EOrbitalType_Planet:
			{
				AddPlanetoid(Cast<UPlanetoid>(Orbital));
				break;
			}
		case EOrbitalType::EOrbitalType_Moon:
			{
				AddPlanetoid(Cast<UPlanetoid>(Orbital));
				break;
			}
		case EOrbitalType::EOrbitalType_Asteroid:
			{
				AddAsteroid(Cast<UAsteroidOrbital>(Orbital));
				break;
			}
		case EOrbitalType::EOrbitalType_Cloud:
			{
				AddCloud(Cast<UCloudOrbital>(Orbital));
				break;
			}
		}
	}
}


void ALocationActor::AddComet()
{
	FTransform Transform;
	ACometActor * CometActor = GetWorld()->SpawnActorDeferred<ACometActor>(LocationClasses->CometActorClass, Transform);
	if(ensure(CometActor))
	{
		CometActor->FinishSpawning(Transform);
		Spawns.Add(Location->GetSystemId(), CometActor);
	}
}

void ALocationActor::AddPlanetoid(UPlanetoid* Planetoid)
{
	FTransform Transform(Planetoid->GetOrbitalLocation());
	Transform.SetRotation(Planetoid->GetOrbitalRotation().Quaternion());
	Transform.SetScale3D(Planetoid->GetOrbitalScale());
	APlanetoidActor * PlanetoidActor = GetWorld()->SpawnActorDeferred<APlanetoidActor>(LocationClasses->PlanetoidActorClasses[Planetoid->GetPlanetType()], Transform);
	if(ensure(PlanetoidActor))
	{
		PlanetoidActor->SetPlanetoid(Planetoid);
		PlanetoidActor->FinishSpawning(Transform);
		Spawns.Add(Planetoid->GetSystemId(), PlanetoidActor);
	}
}

void ALocationActor::AddAsteroid(UAsteroidOrbital* Asteroid)
{
	FTransform Transform(Asteroid->GetOrbitalLocation());
	Transform.SetRotation(Asteroid->GetOrbitalRotation().Quaternion());
	Transform.SetScale3D(Asteroid->GetOrbitalScale());
	AAsteroidActor * AsteroidActor = GetWorld()->SpawnActorDeferred<AAsteroidActor>(LocationClasses->AsteroidActorClass, Transform);
	if(ensure(AsteroidActor))
	{
		AsteroidActor->SetOrbital(Asteroid);
		AsteroidActor->FinishSpawning(Transform);
		Spawns.Add(Asteroid->GetSystemId(), AsteroidActor);
	}
}

void ALocationActor::AddCloud(UCloudOrbital* Cast)
{
	
}

void ALocationActor::AddAsteroidField()
{
	FTransform Transform;
	AAsteroidFieldActor * FieldActor = GetWorld()->SpawnActorDeferred<AAsteroidFieldActor>(LocationClasses->FieldActorClass, Transform);
	if(ensure(FieldActor))
	{
		FieldActor->SetAsteroidField(Cast<UAsteroidField>(Location));
		FieldActor->FinishSpawning(Transform);
		Spawns.Add(Location->GetSystemId(), FieldActor);
	}
}

