// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/PlanetoidGravityComponent.h"

#include "UtilityStatics.h"


// Sets default values for this component's properties
UPlanetoidGravityComponent::UPlanetoidGravityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlanetoidGravityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlanetoidGravityComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UPlanetoidGravityComponent::GetGravityForce(FVector Location) const
{
	if (!ensure(GetOwner()))
	{
		return FVector::ZeroVector;
	}
	return UUtilityStatics::GetVectorFrom(Location, GetOwner()->GetActorLocation()) * (GravityForce * GravityScale);
}

double UPlanetoidGravityComponent::GetDistanceToSurface(FVector Location) const
{
	return 0.0f;
}

