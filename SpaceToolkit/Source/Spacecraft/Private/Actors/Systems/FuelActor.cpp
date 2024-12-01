// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/FuelActor.h"

#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/FuelAttributeSet.h"
#include "Interfaces/ComponentContainerInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelMaxFuelBonusTag,"Fuel.Bonus.MaxFuel","Fuel Max Fuel Bonus");
// Sets default values
AFuelActor::AFuelActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FuelAttributes = CreateDefaultSubobject<UFuelAttributeSet>("FuelAttributes");
	ComponentTag = FuelTankComponentTag;
}

// Called when the game starts or when spawned
void AFuelActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFuelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFuelActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	UFuelDefinitionData * ReactorData = Cast<UFuelDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(FuelMaxFuelBonusTag, ReactorData->MaxFuelBonus));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}

