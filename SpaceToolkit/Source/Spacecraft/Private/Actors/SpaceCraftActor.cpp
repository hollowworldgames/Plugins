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
#include "Attributes/CombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/FTLComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/NavigationSystemComponent.h"
#include "Components/ShipSystemComponent.h"
#include "Components/SpaceFlightModelComponent.h"
#include "Components/TacticalSystemComponent.h"
#include "Data/USpaceCraftDefinitionData.h"
#include "Utility/SpaceCraftGameInstance.h"

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
	CombatAttributes = CreateDefaultSubobject<UCombatAttributeSet>("Combat Attributes");

	Engine = CreateDefaultSubobject<UShipSystemComponent>("Engine Component");
	Engine->SetupAttachment(GetRootComponent());
	Engine->SetChildActorClass(AEngineActor::StaticClass());

	Reactor = CreateDefaultSubobject<UShipSystemComponent>("Reactor Component");
	Reactor->SetupAttachment(GetRootComponent());
	Reactor->SetChildActorClass(AReactorActor::StaticClass());

	FrontShield = CreateDefaultSubobject<UShipSystemComponent>("Front Shield Component");
	FrontShield->SetupAttachment(GetRootComponent());
	FrontShield->SetChildActorClass(AShieldActor::StaticClass());

	RearShield = CreateDefaultSubobject<UShipSystemComponent>("Rear Shield Component");
	RearShield->SetupAttachment(GetRootComponent());
	RearShield->SetChildActorClass(AShieldActor::StaticClass());
	
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
	if (!ensure(AbilitySystemComponent) && !ensure(VitalAttributes)) return;
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	VitalAttributes->OnDead.AddDynamic(this, &ASpaceCraftActor::OnDead);

	Components.Add(LifeSupport->GetComponentTag(), LifeSupport);
	if (!DefaultDefinition.IsNone())
	{
		USpaceCraftGameInstance * Instance = Cast<USpaceCraftGameInstance>(GetGameInstance());
		if (ensure(Instance))
		{
			Initialize(Instance->GetSpaceCraftDefinitionData(DefaultDefinition));
		}
	}
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
	if (ensure(FrontShield) && ensure(FrontShield->GetShipSystemActor()))
	{
		FrontShield->GetShipSystemActor()->SetOn(On);
	}

	if (ensure(RearShield) && ensure(RearShield->GetShipSystemActor()))
	{
		RearShield->GetShipSystemActor()->SetOn(On);
	}

	if (RightShield && ensure(RightShield->GetShipSystemActor()))
	{
		RightShield->GetShipSystemActor()->SetOn(On);
	}

	if (LeftShield && ensure(LeftShield->GetShipSystemActor()))
	{
		LeftShield->GetShipSystemActor()->SetOn(On);
	}
}

bool ASpaceCraftActor::GetShields()
{
	if (ensure(FrontShield) && ensure(FrontShield->GetShipSystemActor()))
	{
		return FrontShield->GetShipSystemActor()->IsOn();
	}
	return false;
}

void ASpaceCraftActor::Initialize(USpaceCraftDefinitionData* Craft)
{
	if (!ensure(Craft)) return;
	
	if(ensure(Battery) && ensure(Battery->GetShipSystemActor()))
	{
		Battery->GetShipSystemActor()->InitializeAttributes(this, Craft->BatteryData);
	}

	if(ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		Reactor->GetShipSystemActor()->InitializeAttributes(this, Craft->ReactorData);
	}

	if(ensure(Engine) && ensure(Engine->GetShipSystemActor()))
	{
		Engine->GetShipSystemActor()->InitializeAttributes(this, Craft->EngineData);
	}

	if(ensure(Fuel) && ensure(Fuel->GetShipSystemActor()))
	{
		Fuel->GetShipSystemActor()->InitializeAttributes(this, Craft->FuelData);
	}

	if(ensure(Sensor) && ensure(Sensor->GetShipSystemActor()))
	{
		Sensor->GetShipSystemActor()->InitializeAttributes(this, Craft->SensorData);
	}

	if(ensure(FrontShield) && ensure(FrontShield->GetShipSystemActor()))
	{
		FrontShield->GetShipSystemActor()->InitializeAttributes(this, Craft->FrontShieldData);
	}

	if(ensure(RearShield) && ensure(RearShield->GetShipSystemActor()))
	{
		RearShield->GetShipSystemActor()->InitializeAttributes(this, Craft->RearShieldData);
	}

	if(RightShield && ensure(RightShield->GetShipSystemActor()))
	{
		RightShield->GetShipSystemActor()->InitializeAttributes(this, Craft->RightShieldData);
	}

	if(LeftShield && ensure(LeftShield->GetShipSystemActor()))
	{
		LeftShield->GetShipSystemActor()->InitializeAttributes(this, Craft->LeftShieldData);
	}
}

void ASpaceCraftActor::Initialize(FName Craft)
{
	USpaceCraftGameInstance * GameInstance = Cast<USpaceCraftGameInstance>(GetGameInstance());
	if (ensure(GameInstance))
	{
		Initialize(GameInstance->GetSpaceCraftDefinitionData(Craft));
	}
}

UGameplayAbilitySystemComponent* ASpaceCraftActor::GetSystem(FGameplayTag System) const
{
	if (Components.Contains(System))
	{
		auto FoundSystem = Components.Find(System);
		if (ensure(*FoundSystem))
		{
			return Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent((*FoundSystem)->GetShipSystemActor()));
		}
	}
	return nullptr;
}

TArray<FGameplayTag> ASpaceCraftActor::GetComponentTags() const
{
	TArray<FGameplayTag> TagArray;
	ComponentTags.GetGameplayTagArray(TagArray);
	return TagArray;
}

void ASpaceCraftActor::ApplyEffectToComponent(FGameplayTag Component, TSubclassOf<UGameplayEffect> Effect, float Level,
	const AActor* Source)
{
	if (Components.Contains(Component))
	{
		auto System = Components.Find(Component);
		if (ensure(*System))
		{
			UGameplayAbilitySystemComponent * ShipComponent =
				Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent((*System)->GetShipSystemActor()));
			if (ensure(ShipComponent))
			{
				ShipComponent->ApplyGameplayEffect(Effect, Level, Source);
			}
		}
	}
}

void ASpaceCraftActor::ApplyDamageToComponent(FGameplayTag Component, float Damage, const AActor * Source)
{
	ApplyEffectToComponent(Component, ComponentDamageEffect, Damage, Source);
}

void ASpaceCraftActor::ReportDamage(const AActor* Source, float EnergyDamage, float KineticDamage, int ShieldFace,
	EDamageReportType Type)
{
}

void ASpaceCraftActor::ReportDamage(const AActor* Source, float EnergyDamage, float KineticDamage,
	EDamageReportType Type)
{
}

void ASpaceCraftActor::ReportComponentDamage(const AActor* Source, float EnergyDamage, float KineticDamage,
	FGameplayTag Component, EDamageReportType Type)
{
}

void ASpaceCraftActor::TogglePower()
{
	if (ensure(Reactor) && ensure(Reactor->GetShipSystemActor()))
	{
		return Reactor->GetShipSystemActor()->SetOn(!GetPower());
	}
}

