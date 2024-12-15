// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/ShipSystemComponent.h"
#include "Actors/Systems/SystemActor.h"


// Sets default values for this component's properties
UShipSystemComponent::UShipSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UShipSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	ShipSystem = Cast<ASystemActor>(GetChildActor());
	
}


// Called every frame
void UShipSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

