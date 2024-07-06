// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SpaceCraft/SpaceCraftActor.h"

#include "SpaceCraft/Components/FTLComponent.h"
#include "SpaceCraft/Components/NavigationSystemComponent.h"
#include "SpaceCraft/Components/SpaceFlightModelComponent.h"
#include "SpaceCraft/Components/TacticalSystemComponent.h"
#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"

// Sets default values
ASpaceCraftActor::ASpaceCraftActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpaceFlightModelComponent = CreateDefaultSubobject<USpaceFlightModelComponent>("Space Flight Model");
	NavigationSystemComponent = CreateDefaultSubobject<UNavigationSystemComponent>("Navigation System");
	TacticalSystemComponent = CreateDefaultSubobject<UTacticalSystemComponent>("Tactical System");
	FTLComponent = CreateDefaultSubobject<UFTLComponent>("FTL");
	Attributes = CreateDefaultSubobject<USpaceCraftAttributes>("Attributes");
}

// Called when the game starts or when spawned
void ASpaceCraftActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCraftActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* ASpaceCraftActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

