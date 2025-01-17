// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/StationComponent.h"

#include "Components/InteractableComponent.h"
#include "Stations/StationPawn.h"


// Sets default values for this component's properties
UStationComponent::UStationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStationComponent::BeginPlay()
{
	Super::BeginPlay();

	Interactor = Cast<UInteractableComponent>(GetChildComponent(0));
	
	AStationPawn * StationPawn = Cast<AStationPawn>(GetChildActor());
	if(ensure(StationPawn))
	{
		StationPawn->SetOwningShip(GetOwner());
		StationPawn->SetInteractor(Interactor);
	}
	
}

void UStationComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}


