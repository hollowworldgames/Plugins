// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/OrbitalComponent.h"

#include "Data/Orbital.h"


// Sets default values for this component's properties
UOrbitalComponent::UOrbitalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOrbitalComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitalComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(Orbital)
	{
		if(Orbital->GetOrbitalType() != EOrbitalType::EOrbitalType_FieldAsteroid)
		{
			GetOwner()->SetActorLocation(Orbital->GetOrbitalLocation());
			GetOwner()->SetActorRotation(Orbital->GetOrbitalRotation());
		}
	}
}

void UOrbitalComponent::SetOrbital(UOrbital* NewOrbital)
{
	Orbital = NewOrbital;
	GetOwner()->SetActorLocation(Orbital->GetOrbitalLocation());
	GetOwner()->SetActorRotation(Orbital->GetOrbitalRotation());
	OnOrbitalSet.Broadcast(Orbital);
}

