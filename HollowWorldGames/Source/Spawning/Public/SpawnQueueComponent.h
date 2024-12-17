// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnQueueComponent.generated.h"


class ISpawnPoint;
class ISpawnable;

USTRUCT(BlueprintType)
struct FSpawnMe
{
	GENERATED_BODY()
	FSpawnMe()
	{
		Spawnable = nullptr;
		Type = 0;
	}
	FSpawnMe(TScriptInterface<ISpawnable> Spawn, int SpawnType)
	{
		Spawnable = Spawn;
		Type = SpawnType;
	}
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	TScriptInterface<ISpawnable> Spawnable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	int Type;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPAWNING_API USpawnQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnQueueComponent();
// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void QueueForSpawn(const TScriptInterface<ISpawnable>& Spawnable, int Type = 0);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	TArray<FSpawnMe> SpawnQueue;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	TArray<TScriptInterface<ISpawnPoint>> SpawnPoints;
};
