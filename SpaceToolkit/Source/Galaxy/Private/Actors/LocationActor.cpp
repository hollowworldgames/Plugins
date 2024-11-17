// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/LocationActor.h"

#include "Components/AsteroidFieldComponent.h"
#include "Components/OrbitalComponent.h"
#include "Data/Location.h"
#include "Data/LocationClasses.h"
#include "Data/Orbital.h"
#include "Utility/GalaxyGameInstance.h"


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

	ClearLocation();
}

// Called every frame
void ALocationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALocationActor::SetLocation(const FSystemId& SystemId)
{
	
}


void ALocationActor::AddComet()
{
	FTransform Transform;
	AActor * CometActor = GetWorld()->SpawnActorDeferred<AActor>(LocationClasses->CometActorClass, Transform);
	if(ensure(CometActor))
	{
		CometActor->FinishSpawning(Transform);
		Spawns.Add(Location->GetSystemId(), CometActor);
	}
}

void ALocationActor::Multicast_SetLocation_Implementation(const FSystemId& SystemId)
{
	UGalaxyGameInstance * Instance = GetWorld()->GetGameInstance<UGalaxyGameInstance>();
	if(ensure(Instance))
	{
		Instance->SetCurrentLocation(SystemId);
		Location = Instance->GetLocation();
		if(!ensure(Location))
		{
			return;
		}
	}
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
		default :
			{
				break;
			}
		}
	}
}

void ALocationActor::ClearLocation()
{
	for(const auto Spawn : Spawns)
	{
		Spawn.Value->Destroy();
	}
	Spawns.Empty();
}

void ALocationActor::AddPlanetoid(UPlanetoid* Planetoid)
{
	FTransform Transform(Planetoid->GetOrbitalLocation());
	Transform.SetRotation(Planetoid->GetOrbitalRotation().Quaternion());
	Transform.SetScale3D(Planetoid->GetOrbitalScale());
	AActor * PlanetoidActor = GetWorld()->SpawnActorDeferred<AActor>(LocationClasses->PlanetoidActorClasses[Planetoid->GetPlanetType()], Transform);
	if(ensure(PlanetoidActor))
	{
		UOrbitalComponent * Component = PlanetoidActor->GetComponentByClass<UOrbitalComponent>();
		if(ensure(Component))
		{
			Component->SetOrbital(Planetoid);
		}
		PlanetoidActor->FinishSpawning(Transform);
		Spawns.Add(Planetoid->GetSystemId(), PlanetoidActor);
	}
}

void ALocationActor::AddAsteroid(UAsteroidOrbital* Asteroid)
{
	FTransform Transform(Asteroid->GetOrbitalLocation());
	Transform.SetRotation(Asteroid->GetOrbitalRotation().Quaternion());
	Transform.SetScale3D(Asteroid->GetOrbitalScale());
	AActor * AsteroidActor = GetWorld()->SpawnActorDeferred<AActor>(LocationClasses->AsteroidActorClass, Transform);
	if(ensure(AsteroidActor))
	{
		UOrbitalComponent * Component = AsteroidActor->GetComponentByClass<UOrbitalComponent>();
		if(ensure(Component))
		{
			Component->SetOrbital(Asteroid);
		}
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
	AActor * FieldActor = GetWorld()->SpawnActorDeferred<AActor>(LocationClasses->FieldActorClass, Transform);
	if(ensure(FieldActor))
	{
		UAsteroidFieldComponent * AsteroidFieldComponent = FieldActor->GetComponentByClass<UAsteroidFieldComponent>();
		if(ensure(AsteroidFieldComponent))
		{
			AsteroidFieldComponent->SetField(Cast<UAsteroidField>(Location));
		}
		FieldActor->FinishSpawning(Transform);
		Spawns.Add(Location->GetSystemId(), FieldActor);
	}
}

