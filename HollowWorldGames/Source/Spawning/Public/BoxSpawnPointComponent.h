// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SpawnPoint.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "BoxSpawnPointComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPAWNING_API UBoxSpawnPointComponent : public UBoxComponent , public ISpawnPoint
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBoxSpawnPointComponent();
	virtual APawn * Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable) override;
	virtual bool IsOccupied() override;
	virtual FVector GetLocation() override;
	virtual FRotator GetRotation() override;
	virtual int GetSpawnType() override;
	virtual int GetSpawnFaction() override { return 0; }
	virtual FName GetSpawnName_Implementation() override { return Name; }
protected:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Status)
	TObjectPtr<AActor> Occupant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Status)
	FName Name;
};
