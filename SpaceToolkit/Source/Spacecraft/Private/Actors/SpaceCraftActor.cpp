// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Actors/SpaceCraftActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "MovieSceneSequenceID.h"
#include "Actors/Systems/BatteryActor.h"
#include "Actors/Systems/EngineActor.h"
#include "Actors/Systems/FuelActor.h"
#include "Actors/Systems/LifeSupportActor.h"
#include "Actors/Systems/ReactorActor.h"
#include "Actors/Systems/SensorActor.h"
#include "Actors/Systems/ShieldActor.h"
#include "Actors/Systems/SystemActor.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/FTLComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/NavigationSystemComponent.h"
#include "Components/ShipSystemComponent.h"
#include "Components/SpaceFlightModelComponent.h"
#include "Components/TacticalSystemComponent.h"

// Sets default values
ASpaceCraftActor::ASpaceCraftActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpaceFlightModelComponent = CreateDefaultSubobject<USpaceFlightModelComponent>("Space Flight Model");
	NavigationSystemComponent = CreateDefaultSubobject<UNavigationSystemComponent>("Navigation System");
	TacticalSystemComponent = CreateDefaultSubobject<UTacticalSystemComponent>("Tactical System");
	FTLComponent = CreateDefaultSubobject<UFTLComponent>("FTL");
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	VitalAttributes = CreateDefaultSubobject<UVitalAttributeSet>("Vital Attributes");

	Engine = CreateDefaultSubobject<UShipSystemComponent>("Engine Component");
	Engine->SetupAttachment(GetRootComponent());
	Engine->SetChildActorClass(AEngineActor::StaticClass());

	Reactor = CreateDefaultSubobject<UShipSystemComponent>("Reactor Component");
	Reactor->SetupAttachment(GetRootComponent());
	Reactor->SetChildActorClass(AReactorActor::StaticClass());

	Shield = CreateDefaultSubobject<UShipSystemComponent>("Shield Component");
	Shield->SetupAttachment(GetRootComponent());
	Shield->SetChildActorClass(AShieldActor::StaticClass());

	Battery = CreateDefaultSubobject<UShipSystemComponent>("Battery Component");
	Battery->SetupAttachment(GetRootComponent());
	Battery->SetChildActorClass(ABatteryActor::StaticClass());

	Fuel = CreateDefaultSubobject<UShipSystemComponent>("Fuel Component");
	Fuel->SetupAttachment(GetRootComponent());
	Fuel->SetChildActorClass(AFuelActor::StaticClass());

	Sensor = CreateDefaultSubobject<UShipSystemComponent>("Sensor Component");
	Sensor->SetupAttachment(GetRootComponent());
	Sensor->SetChildActorClass(ASensorActor::StaticClass());

	LifeSupport = CreateDefaultSubobject<UShipSystemComponent>("LifeSupport Component");
	LifeSupport->SetupAttachment(GetRootComponent());
	LifeSupport->SetChildActorClass(ALifeSupportActor::StaticClass());
}

// Called when the game starts or when spawned
void ASpaceCraftActor::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	VitalAttributes->OnDead.AddDynamic(this, &ASpaceCraftActor::OnDead);
}

void ASpaceCraftActor::OnDead_Implementation()
{
	Destroy();
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

void ASpaceCraftActor::ToggleGear()
{
	OnGearToggle.Broadcast();
}

void ASpaceCraftActor::LowerGear()
{
}

void ASpaceCraftActor::RaiseGear()
{
}

EGearState ASpaceCraftActor::GetGearState()
{
	return EGearState::Lowered;
}

void ASpaceCraftActor::SetPower(bool On)
{
	if (ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		Reactor->GetShipSystemActor()->SetOn(On);
	}
}

bool ASpaceCraftActor::GetPower()
{
	if (ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		return Reactor->GetShipSystemActor()->IsOn();
	}
	return false;
}

void ASpaceCraftActor::ToggleEngines()
{
	SetEngines(!GetEngines());
}

void ASpaceCraftActor::SetEngines(bool On)
{
	if (ensure(Engine) && ensure(Engine->GetShipSystemActor()))
	{
		Engine->GetShipSystemActor()->SetOn(On);
	}
}

bool ASpaceCraftActor::GetEngines()
{
	if (ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		return Reactor->GetShipSystemActor()->IsOn();
	}
	return false;
}

void ASpaceCraftActor::ToggleShields()
{
	SetShields(!GetShields());
}

void ASpaceCraftActor::SetShields(bool On)
{
	if (ensure(Shield) && ensure(Shield->GetShipSystemActor()))
	{
		Shield->GetShipSystemActor()->SetOn(On);
	}
}

bool ASpaceCraftActor::GetShields()
{
	if (ensure(Shield) && ensure(Shield->GetShipSystemActor()))
	{
		return Shield->GetShipSystemActor()->IsOn();
	}
	return false;
}

UAbilitySystemComponent* ASpaceCraftActor::GetSystem(EShipSystem System)
{
	switch (System)
	{
	case EShipSystem::Reactor:
		return (Reactor) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Reactor->GetShipSystemActor()) : nullptr;
	case EShipSystem::Engine:
		return (Engine) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Engine->GetShipSystemActor()) : nullptr;
	case EShipSystem::Shield:
		return (Shield) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Shield->GetShipSystemActor()) : nullptr;
	case EShipSystem::Battery:
		return (Battery) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Battery->GetShipSystemActor()) : nullptr;
	case EShipSystem::Fuel:
		return (Fuel) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Fuel->GetShipSystemActor()) : nullptr;
	case EShipSystem::Sensor :
		return (Sensor) ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Sensor->GetShipSystemActor()) : nullptr;
	default: ;
	}
	return nullptr;
}

void ASpaceCraftActor::TogglePower()
{
	if (ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		return Reactor->GetShipSystemActor()->SetOn(!GetPower());
	}
}

