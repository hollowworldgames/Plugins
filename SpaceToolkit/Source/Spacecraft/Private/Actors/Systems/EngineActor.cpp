// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/EngineActor.h"

#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/EngineAttributeSet.h"
#include "Interfaces/ComponentContainerInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnginePowerToThrustBonusTag,"Engine.Bonus.PowerToThrust","Engine Power To Thrust Bonus");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EngineMaxRCSThrustBonusTag,"Engine.Bonus.MaxRCSThrust","Engine Max RCS Thrust Bonus");

// Sets default values
AEngineActor::AEngineActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Engine = CreateDefaultSubobject<UEngineAttributeSet>("Engine Attributes");
	ComponentTag = EngineComponentTag;
	StartTag = EngineOnTag;
}

// Called when the game starts or when spawned
void AEngineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEngineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEngineActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	UEngineDefinitionData * EngineData = Cast<UEngineDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(EnginePowerToThrustBonusTag, EngineData->ThrustToPowerBonus));
		Values.Add(FCustomEffectValue(EngineMaxRCSThrustBonusTag, EngineData->MaxRCSThrustBonus));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}

