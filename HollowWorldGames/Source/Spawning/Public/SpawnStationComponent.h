// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "InteractableStationComponent.h"
#include "SpawnStationComponent.generated.h"


class USpawnerWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPAWNING_API USpawnStationComponent : public UInteractableStationComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnStationComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category="Spawning")
	USpawnerWidget * GetSpawnerWidget() const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
