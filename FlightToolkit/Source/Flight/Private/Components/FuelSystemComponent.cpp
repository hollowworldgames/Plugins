// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FuelSystemComponent.h"

#include "Components/PowerSystemComponent.h"
#include "Definitions/FuelTankDefinition.h"


// Sets default values for this component's properties
UFuelSystemComponent::UFuelSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

EResource UFuelSystemComponent::GetProvided()
{
	return EResource::Fuel;
}

float UFuelSystemComponent::Consume(float Amount)
{
	return Amount;
}

void UFuelSystemComponent::AddConsumer(TScriptInterface<IConsumer> Consumer)
{
	Consumers.Add(Consumer);
}

float UFuelSystemComponent::Provided(float Amount)
{
	PowerAvailable = Amount;
	return Amount;
}

EResource UFuelSystemComponent::GetNeededResource()
{
	return EResource::Power;
}

float UFuelSystemComponent::GetNeeded()
{
	return PowerNeeded;
}


// Called when the game starts
void UFuelSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	for(TSubclassOf<UFuelTankDefinition> definition : FuelTankClasses)
	{
		int index = FuelTanks.Add(NewObject<UFuelTankDefinition>(definition));
	}

	UPowerSystemComponent * PowerSystemComponent = GetOwner()->GetComponentByClass<UPowerSystemComponent>();
	if(ensure(PowerSystemComponent))
	{
		PowerSystemComponent->AddConsumer(TObjectPtr<UFuelSystemComponent>(this));
	}
}


// Called every frame
void UFuelSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	for(UFuelTankDefinition * FuelTankDefinition : FuelTanks)
	{
		if(FuelTankDefinition)
		{
			if(TScriptInterface<IConsumer> Target = GetTarget(FuelTankDefinition->GetTarget()))
			{
				FuelTankDefinition->Consume(Target->Provided(Target->GetNeeded() * DeltaTime));
			}
		}
	}
}

TScriptInterface<IConsumer> UFuelSystemComponent::GetTarget(FGameplayTag Tag) const
{
	for(TScriptInterface<IConsumer> Consumer : Consumers)
	{
		if(Consumer->GetComponentTag().MatchesTag(Tag))
		{
			return Consumer;
		}
	}
	for(UFuelTankDefinition * FuelTankDefinition : FuelTanks)
	{
		if(FuelTankDefinition && FuelTankDefinition->GetComponentId().MatchesTag(Tag))
		{
			return TObjectPtr<UFuelTankDefinition>(FuelTankDefinition);
		}
	}
	return nullptr;
}

TScriptInterface<ISource> UFuelSystemComponent::GetSource(FGameplayTag Tag) const
{
	for(UFuelTankDefinition * FuelTankDefinition : FuelTanks)
	{
		if(FuelTankDefinition && FuelTankDefinition->GetComponentId().MatchesTag(Tag))
		{
			return TObjectPtr<UFuelTankDefinition>(FuelTankDefinition);
		}
	}
	return nullptr;
}

