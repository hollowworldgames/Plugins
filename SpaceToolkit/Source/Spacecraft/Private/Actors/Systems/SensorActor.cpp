// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/SensorActor.h"

#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/SensorAttributeSet.h"
#include "Interfaces/ComponentContainerInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(SensorStrengthBonusTag,"Sensor.Bonus.Strength","Sensor Bonus Strength");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(SensorResolutionBonusTag,"Sensor.Bonus.Resolution","Sensor Bonus Resolution");

// Sets default values
ASensorActor::ASensorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SensorAttributes = CreateDefaultSubobject<USensorAttributeSet>("Sensor Attributes");
	ComponentTag = SensorComponentTag;
}

// Called when the game starts or when spawned
void ASensorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASensorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASensorActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	USensorDefinitionData * SensorData = Cast<USensorDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(SensorStrengthBonusTag, SensorData->SignalStrength));
		Values.Add(FCustomEffectValue(SensorResolutionBonusTag, SensorData->SignalResolution));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}

