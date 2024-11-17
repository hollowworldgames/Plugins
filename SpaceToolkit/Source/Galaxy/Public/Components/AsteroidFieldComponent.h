// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AsteroidFieldComponent.generated.h"


class UFieldAsteroid;
class UAsteroidField;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddAsteroid, UFieldAsteroid*, FieldAsteroid);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GALAXY_API UAsteroidFieldComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAsteroidFieldComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void SetField(UAsteroidField * Field);
	void AddAsteroid(UFieldAsteroid * Asteroid);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Data)
	UAsteroidField * Field;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Components)
	TMap<UStaticMesh*, TObjectPtr<UInstancedStaticMeshComponent>> AsteroidComponents;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Data)
	TArray<UFieldAsteroid*> Asteroids;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAddAsteroid OnAddAsteroid;
};
