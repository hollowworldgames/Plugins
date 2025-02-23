// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Components/Systems/SystemComponent.h"


// Sets default values for this component's properties
USystemComponent::USystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USystemComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsLocallyControlled() || SimulateBoth)
	{
		Simulate(DeltaTime);
	}
	else
	{
		
	}
}


// Called when the game starts
void USystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void USystemComponent::Simulate(float DeltaTime)
{
}

bool USystemComponent::IsLocallyControlled() const
{
	return true;
}

bool USystemComponent::IsPlayerControlled() const
{
	return true;
}

