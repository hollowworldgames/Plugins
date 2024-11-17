// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/SolarSystemActor.h"

#include "Actors/StarActor.h"
#include "Data/SolarSystem.h"


// Sets default values
ASolarSystemActor::ASolarSystemActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASolarSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolarSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASolarSystemActor::SetSolarSystem(const FSystemId& SystemId)
{
	Multicast_SetSolarSystem(SystemId);
}

void ASolarSystemActor::ClearSystem()
{
	for(TObjectPtr<AStarActor> Star : Stars)
	{
		Star->Destroy();
	}
	Stars.Empty();
}

FSystemId ASolarSystemActor::GetSystemId() const
{
	if(ensure(SolarSystem))
	{
		return SolarSystem->GetSystemId();
	}
	return FSystemId();
}

void ASolarSystemActor::Multicast_SetSolarSystem_Implementation(const FSystemId& SystemId)
{
	UGalaxyGameInstance * Instance = Cast<UGalaxyGameInstance>(GetGameInstance());
	if(ensure(Instance))
	{
		Instance->SetCurrentLocation(SystemId);
		SolarSystem = Instance->GetCurrentSolarSystem();
	}
	for(UStar * Star : SolarSystem->GetStars())
	{
		FTransform Transform;
		AStarActor * NewStar = GetWorld()->SpawnActorDeferred<AStarActor>(StarClass, Transform);
		if(ensure(NewStar))
		{
			NewStar->SetStar(Star);
			Stars.Add(NewStar);
			NewStar->FinishSpawning(Transform);
		}
	}
}

