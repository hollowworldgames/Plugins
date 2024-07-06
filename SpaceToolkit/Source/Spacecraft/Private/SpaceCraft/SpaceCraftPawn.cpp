// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpaceCraft/SpaceCraftPawn.h"

#include "SpaceCraft/Components/FTLComponent.h"
#include "SpaceCraft/Components/NavigationSystemComponent.h"
#include "SpaceCraft/Components/SpaceFlightModelComponent.h"
#include "SpaceCraft/Components/TacticalSystemComponent.h"
#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"

ASpaceCraftPawn::ASpaceCraftPawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpaceFlightModelComponent = CreateDefaultSubobject<USpaceFlightModelComponent>("Space Flight Model");
	NavigationSystemComponent = CreateDefaultSubobject<UNavigationSystemComponent>("Navigation System");
	TacticalSystemComponent = CreateDefaultSubobject<UTacticalSystemComponent>("Tactical System");
	FTLComponent = CreateDefaultSubobject<UFTLComponent>("FTL");
	Attributes = CreateDefaultSubobject<USpaceCraftAttributes>("Attributes");
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
