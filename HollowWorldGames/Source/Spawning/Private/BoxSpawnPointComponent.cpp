// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved


#include "BoxSpawnPointComponent.h"

#include "Spawnable.h"

// Sets default values for this component's properties
UBoxSpawnPointComponent::UBoxSpawnPointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

APawn* UBoxSpawnPointComponent::Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
{
	return Spawnable->Spawn(GetWorld(), TObjectPtr<UBoxSpawnPointComponent>(this));
}

bool UBoxSpawnPointComponent::IsOccupied()
{
	return Occupant;
}

FVector UBoxSpawnPointComponent::GetLocation()
{
	return GetComponentLocation();
}

FRotator UBoxSpawnPointComponent::GetRotation()
{
	return GetComponentRotation();
}

int UBoxSpawnPointComponent::GetSpawnType()
{
	return 0;
}

void UBoxSpawnPointComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!Occupant)
	{
		Occupant = OtherActor;
	}
}

void UBoxSpawnPointComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(Occupant == OtherActor)
	{
		Occupant = nullptr;
	}
}


// Called when the game starts
void UBoxSpawnPointComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UBoxSpawnPointComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UBoxSpawnPointComponent::OnEndOverlap);
}

void UBoxSpawnPointComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	OnComponentBeginOverlap.Clear();
	OnComponentEndOverlap.Clear();
}
