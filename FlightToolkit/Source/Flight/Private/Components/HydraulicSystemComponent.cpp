// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/HydraulicSystemComponent.h"

#include "Components/PowerSystemComponent.h"
#include "Definitions/HydraulicReservoirDefinition.h"


// Sets default values for this component's properties
UHydraulicSystemComponent::UHydraulicSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHydraulicSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	for(TSubclassOf<UHydraulicReservoirDefinition> ReservoirClass : ReservoirClasses)
	{
		Reservoirs.Add(NewObject<UHydraulicReservoirDefinition>(ReservoirClass));
	}

	UPowerSystemComponent * PowerSystemComponent = GetOwner()->GetComponentByClass<UPowerSystemComponent>();
	if(ensure(PowerSystemComponent))
	{
		PowerSystemComponent->AddConsumer(TObjectPtr<UHydraulicSystemComponent>(this));
	}
}


// Called every frame
void UHydraulicSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	for(TObjectPtr<UHydraulicReservoirDefinition> Reservoir : Reservoirs)
	{
		Reservoir->TickReservoir(DeltaTime, Power);
	}
}

float UHydraulicSystemComponent::Consume(float Amount)
{
	Power = Amount;
	return Amount;
}

void UHydraulicSystemComponent::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
	Consumers.Add(Consumer);
}

float UHydraulicSystemComponent::GetNeeded()
{
	return 0.1f;
}

float UHydraulicSystemComponent::Provided(float Amount)
{
	return Amount;
}

