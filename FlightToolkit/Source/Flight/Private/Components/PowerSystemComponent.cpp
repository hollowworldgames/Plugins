// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/PowerSystemComponent.h"

#include "Components/FlightModelComponent.h"
#include "Definitions/BatteryDefinition.h"
#include "Definitions/GeneratorDefinition.h"


// Sets default values for this component's properties
UPowerSystemComponent::UPowerSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


float UPowerSystemComponent::Consume(float Amount)
{
	return Amount;
}

void UPowerSystemComponent::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
	Consumers.Add(Consumer);
}

// Called when the game starts
void UPowerSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for(TSubclassOf<UGeneratorDefinition> GeneratorClass : GeneratorClasses)
	{
		Generators.Add(NewObject<UGeneratorDefinition>(GeneratorClass));
	}
}


// Called every frame
void UPowerSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	
	UFlightModelComponent * FlightModelComponent = GetOwner()->GetComponentByClass<UFlightModelComponent>();
	if(ensure(FlightModelComponent))
	{
		PowerGenerated = 0;
		for(UGeneratorDefinition * Generator : Generators)
		{
			Generator->Generate(FlightModelComponent->GetEngineRPM(Generator->GetEngineTag()));
			PowerGenerated += Generator->GetPowerAvailable();
			
		}

		for(TScriptInterface<IConsumer> Consumer : Consumers)
		{
			if(PowerGenerated > Consumer->GetNeeded())
			{
				PowerGenerated = FMath::Clamp(PowerGenerated - Consumer->GetNeeded(),0, PowerGenerated);
				Consumer->Provided(Consumer->GetNeeded());
			}
			else if(Battery && Battery->GetAvailable() > Consumer->GetNeeded()) //pull from battery
			{
				Battery->Consume(Consumer->Provided(Consumer->GetNeeded()) * DeltaTime);
			}
		}

		if(PowerGenerated > 0)
		{
			Battery->AddPower(PowerGenerated * DeltaTime);
		}
	}
}

