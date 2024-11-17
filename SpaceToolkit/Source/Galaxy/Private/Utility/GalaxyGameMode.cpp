// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Utility/GalaxyGameMode.h"

#include "Actors/GalaxyActor.h"
#include "Actors/LocationActor.h"
#include "Actors/SolarSystemActor.h"
#include "Utility/GalaxyGameInstance.h"

void AGalaxyGameMode::SetCurrentLocation(const FSystemId& SystemId)
{
	if(ensure(LocationActor))
	{
		LocationActor->ClearLocation();
	}

	if(ensure(SolarSystemActor) && !SystemId.IsSameSystem(SolarSystemActor->GetSystemId()))
	{
		SolarSystemActor->ClearSystem();
	}

	//Clear Spawned items
	DespawnTraffic();
	
	UGalaxyGameInstance * Instance = Cast<UGalaxyGameInstance>(GetGameInstance());
	if(Instance)
	{
		Instance->SetCurrentLocation(SystemId);
		if(ensure(GalaxyActor))
		{
			GalaxyActor->RenderGalaxy(SystemId, Instance->GetGalaxyAsset());
		}
	}

	if(ensure(SolarSystemActor) && ensure(LocationActor))
	{
		LocationActor->SetLocation(Instance->GetCurrentLocation());
		if(!SolarSystemActor->GetSystemId().IsSameSystem(Instance->GetCurrentLocation()))
		{
			SolarSystemActor->SetSolarSystem(Instance->GetCurrentLocation());
		}
	}	
}

void AGalaxyGameMode::AddTraffic(AActor* Actor)
{
	Traffic.Add(Actor);
}

void AGalaxyGameMode::RemoveTraffic(AActor* Actor)
{
	Traffic.Remove(Actor);
}

TArray<AActor*> AGalaxyGameMode::GetTraffic() const
{
	return Traffic;
}

void AGalaxyGameMode::DespawnTraffic()
{
	for(AActor * Actor : Traffic)
	{
		Actor->Destroy();
	}
	Traffic.Empty();
}

void AGalaxyGameMode::BeginPlay()
{
	Super::BeginPlay();
	UGalaxyGameInstance * Instance = Cast<UGalaxyGameInstance>(GetGameInstance());
	if(Instance)
	{
		FTransform Transform;
		Transform.SetLocation(FVector::Zero());
		LocationActor = GetWorld()->SpawnActorDeferred<ALocationActor>(LocationActorClass, Transform);
		if(ensure(LocationActor))
		{
			LocationActor->SetLocation(Instance->GetCurrentLocation());
			LocationActor->FinishSpawning(Transform);
		}

		SolarSystemActor = GetWorld()->SpawnActorDeferred<ASolarSystemActor>(SolarSystemActorClass, Transform);
		if(ensure(SolarSystemActor))
		{
			SolarSystemActor->SetSolarSystem(Instance->GetCurrentLocation());
			SolarSystemActor->FinishSpawning(Transform);
		}

		GalaxyActor = GetWorld()->SpawnActorDeferred<AGalaxyActor>(GalaxyActorClass, Transform);
		if(ensure(GalaxyActor))
		{
			GalaxyActor->RenderGalaxy(Instance->GetCurrentLocation(), Instance->GetGalaxyAsset());
		}
	}
}

void AGalaxyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	DespawnTraffic();
	if(LocationActor)
	{
		LocationActor->Destroy();
	}

	if(SolarSystemActor)
	{
		SolarSystemActor->Destroy();
	}

	if(GalaxyActor)
	{
		GalaxyActor->Destroy();
	}
}
