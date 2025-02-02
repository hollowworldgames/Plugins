// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/CharacterAutoRunComponent.h"

#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "Components/SplineComponent.h"


// Sets default values for this component's properties
UCharacterAutoRunComponent::UCharacterAutoRunComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterAutoRunComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SplineComponent = GetOwner()->FindComponentByClass<USplineComponent>();
}


// Called every frame
void UCharacterAutoRunComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AutoRun)
	{
		MoveToPoint();
	}

	
}

void UCharacterAutoRunComponent::SetAutoRunDestination(const FVector& Destination)
{
	APawn * MyPawn = GetOwner<APawn>();
	if(ensure(MyPawn))
	{
		UNavigationPath * Path = UNavigationSystemV1::FindPathToLocationSynchronously(GetWorld(), MyPawn->GetActorLocation(), Destination);
		if(Path)
		{
			SplineComponent->ClearSplinePoints();
			for(const FVector& Location : Path->PathPoints)
			{
				SplineComponent->AddSplinePoint(Location, ESplineCoordinateSpace::World);
				CachedLocation = Location;
				DrawDebugSphere(GetWorld(), Location, 50, 8, FColor::White, false, 5);
			}
			
			AutoRun = true;
		}
	}
}

void UCharacterAutoRunComponent::MoveToPoint()
{
	APawn * ControlledPawn = GetOwner<APawn>();
	if(ensure(IsValid(ControlledPawn)))
	{
		const FVector LocationOnSpline = SplineComponent->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
		const FVector Direction = SplineComponent->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
		const float Distance = FVector::Distance(CachedLocation, LocationOnSpline);
		if(Distance <= AutorunAcceptanceRadius)
		{
				
			SplineComponent->ClearSplinePoints();
			AutoRun = false;
		}
		else
		{
			ControlledPawn->AddMovementInput(Direction);
		}
	}
}

