// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Aircraft/AircraftPawn.h"

#include "ConverterStatics.h"
#include "Components/FireControlComponent.h"
#include "Components/FlightModelComponent.h"
#include "Components/FuelSystemComponent.h"
#include "Components/PowerSystemComponent.h"


// Sets default values
AAircraftPawn::AAircraftPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FlightModelComponent = CreateDefaultSubobject<UFlightModelComponent>("Flight Model");
	FuelSystemComponent = CreateDefaultSubobject<UFuelSystemComponent>("Fuel System");
	PowerSystemComponent = CreateDefaultSubobject<UPowerSystemComponent>("Power System");
	FireControlComponent = CreateDefaultSubobject<UFireControlComponent>("Fire Control System");
}

// Called when the game starts or when spawned
void AAircraftPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAircraftPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAircraftPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


