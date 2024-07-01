// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved


#include "CapsuleSpawnPointComponent.h"

#include "Spawnable.h"

// Sets default values for this component's properties
UCapsuleSpawnPointComponent::UCapsuleSpawnPointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CapsuleHalfHeight = 1.0f;
	// ...
}

APawn* UCapsuleSpawnPointComponent::Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
{
	return Spawnable->Spawn(GetWorld(), TObjectPtr<UCapsuleSpawnPointComponent>(this));
}

bool UCapsuleSpawnPointComponent::IsOccupied()
{
	return Occupant;
}

FVector UCapsuleSpawnPointComponent::GetLocation()
{
	return GetComponentLocation();
}

FRotator UCapsuleSpawnPointComponent::GetRotation()
{
	return GetComponentRotation();
}

int UCapsuleSpawnPointComponent::GetSpawnType()
{
	return 0;
}

void UCapsuleSpawnPointComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!Occupant)
	{
		Occupant = OtherActor;
	}
}

void UCapsuleSpawnPointComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(Occupant == OtherActor)
	{
		Occupant = nullptr;
	}
}


// Called when the game starts
void UCapsuleSpawnPointComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UCapsuleSpawnPointComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UCapsuleSpawnPointComponent::OnEndOverlap);
}

void UCapsuleSpawnPointComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	OnComponentBeginOverlap.Clear();
	OnComponentEndOverlap.Clear();
}

