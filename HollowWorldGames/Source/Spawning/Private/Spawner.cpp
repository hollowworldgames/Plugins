// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Spawner.h"

#include "SpawnPoint.h"

/*// Add default functionality here for any ISpawner functions that are not pure virtual.
void ISpawner::AddSpawnPoint_Implementation(USceneComponent* spawnPoint)
{
	TScriptInterface<ISpawnPoint> NewSpawn;
	NewSpawn.SetObject(spawnPoint);
	NewSpawn.SetInterface(Cast<ISpawnPoint>(spawnPoint));
	AddSpawn(NewSpawn);
}*/

bool ISpawner::SpawnAt_Implementation(const TScriptInterface<ISpawnable>& Spawnable,
	const TScriptInterface<ISpawnPoint>& SpawnPoint)
{
	if(ensure(Spawnable) && ensure(SpawnPoint))
	{
		return SpawnPoint->Execute_Spawn(SpawnPoint.GetObject(), Spawnable) != nullptr;
	}
	return false;
}
