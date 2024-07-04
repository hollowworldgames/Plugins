// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FireControlComponent.h"

#include "Components/PowerSystemComponent.h"
#include "Definitions/Sensors/SensorDefinition.h"


// Sets default values for this component's properties
UFireControlComponent::UFireControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFireControlComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UPowerSystemComponent * PowerSystemComponent = GetOwner()->GetComponentByClass<UPowerSystemComponent>();
	if(ensure(PowerSystemComponent))
	{
		for(TSubclassOf<USensorDefinition> SensorClass : SensorClasses)
		{
			TObjectPtr<USensorDefinition> Sensor = NewObject<USensorDefinition>(SensorClass);
			Sensors.Add(Sensor);
			PowerSystemComponent->AddConsumer(Sensor);
		}
	}
}


// Called every frame
void UFireControlComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for(TObjectPtr<USensorDefinition> Sensor : Sensors)
	{
		Sensor->SensorTick(DeltaTime, GetOwner());
	}
}

