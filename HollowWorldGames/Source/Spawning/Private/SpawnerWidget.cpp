// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpawnerWidget.h"

#include "UtilityStatics.h"
#include "InteractableStationComponent.h"
#include "Interactor.h"
#include "SpawnController.h"
#include "Kismet/GameplayStatics.h"
#include "Spawner.h"
#include "SpawnerActor.h"
#include "SpawnerPawn.h"
#include "SpawnPoint.h"

void USpawnerWidget::SetSpawnerActor(ASpawnerActor * Actor)
{
	ensure(Actor);
	Spawner.SetInterface(Cast<ISpawner>(Actor));
	Spawner.SetObject(Actor);
	ensure(Spawner);
}

void USpawnerWidget::SetSpawnerPawn(ASpawnerPawn* Pawn)
{
	ensure(Pawn);
	Spawner.SetInterface(Cast<ISpawner>(Pawn));
	Spawner.SetObject(Pawn);
	ensure(Spawner);
}

void  USpawnerWidget::NextSpawnable()
{
	APlayerController * Controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Controller)
	{
		//Controller->NextSpawnable_Server(Cast<AActor>(Spawner.GetObject()));
	}
}

void  USpawnerWidget::PreviousSpawnable()
{
	APlayerController * Controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Controller)
	{
		//Controller->NextSpawnable_Server(Cast<AActor>(Spawner.GetObject()));
	}
}

TScriptInterface<ISpawnable> USpawnerWidget::GetCurrentSpawnable()
{
	return nullptr;
}

void USpawnerWidget::NextSpawnPoint()
{
	ISpawnController * Controller = Cast<ISpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Controller)
	{
		Controller->NextSpawnPoint(Cast<AActor>(Spawner.GetObject()));
	}
}

void USpawnerWidget::PreviousSpawnPoint()
{
	ISpawnController * Controller = Cast<ISpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Controller)
	{
		Controller->PreviousSpawnPoint(Cast<AActor>(Spawner.GetObject()));
	}
}

TScriptInterface<ISpawnable> USpawnerWidget::GetCurrentSpawnPoint()
{
	ISpawnController * Controller = Cast<ISpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Controller)
	{
		return Controller->GetSpawnPoint();
	}
	return nullptr;
}

void USpawnerWidget::Spawn()
{
	ISpawnController * Controller = Cast<ISpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(ensure(Controller))
	{
		Controller->OnSpawn(Cast<AActor>(Spawner.GetObject()));
	}
}

void USpawnerWidget::SpawnRandom()
{
	ISpawnController * Controller = Cast<ISpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(ensure(Controller))
	{
		Controller->OnSpawnRandom(Cast<AActor>(Spawner.GetObject()));
	}
}

void USpawnerWidget::OnInteraction()
{
	if(Spawner)
	{
		AActor * actor = Cast<AActor>(Spawner.GetObject());
		if(actor)
		{
			UInteractableStationComponent * Component = actor->GetComponentByClass<UInteractableStationComponent>();
			if(Component)
			{
				Component->OnInteraction(Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)));
			}
		}
	}
}
