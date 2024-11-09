// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Utility/GalaxyGameMode.h"

#include "Actors/LocationActor.h"
#include "Actors/SolarSystemActor.h"
#include "Utility/GalaxyGameInstance.h"

void AGalaxyGameMode::BeginPlay()
{
	Super::BeginPlay();
	UGalaxyGameInstance * Instance = Cast<UGalaxyGameInstance>(GetGameInstance());
	if(Instance)
	{
		FTransform Transform;
		LocationActor = GetWorld()->SpawnActorDeferred<ALocationActor>(LocationActorClass, Transform);
		if(LocationActor)
		{
			LocationActorr
			LocationActor->FinishSpawning(Transform);
		}

		SolarSystemActor = GetWorld()->SpawnActorDeferred<ASolarSystemActor>(SolarSystemActorClass, Transform);
		if(SolarSystemActor)
		{
			SolarSystemActor->FinishSpawning(Transform);
		}
	}
}

void AGalaxyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if(LocationActor)
	{
		GetWorld()->DestroyActor(LocationActor);
	}

	if(SolarSystemActor)
	{
		GetWorld()->DestroyActor(SolarSystemActor);
	}
}
