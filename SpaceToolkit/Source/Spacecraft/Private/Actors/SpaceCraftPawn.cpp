// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Actors/SpaceCraftPawn.h"

#include "Components/FTLComponent.h"
#include "Components/NavigationSystemComponent.h"
#include "Components/SpaceFlightModelComponent.h"
#include "Components/TacticalSystemComponent.h"

ASpaceCraftPawn::ASpaceCraftPawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpaceFlightModelComponent = CreateDefaultSubobject<USpaceFlightModelComponent>("Space Flight Model");
	NavigationSystemComponent = CreateDefaultSubobject<UNavigationSystemComponent>("Navigation System");
	TacticalSystemComponent = CreateDefaultSubobject<UTacticalSystemComponent>("Tactical System");
	FTLComponent = CreateDefaultSubobject<UFTLComponent>("FTL");
}

void ASpaceCraftPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

UAbilitySystemComponent* ASpaceCraftPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASpaceCraftPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
