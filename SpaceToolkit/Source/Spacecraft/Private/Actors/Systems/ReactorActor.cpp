// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/ReactorActor.h"

#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/ReactorAttributeSet.h"
#include "Interfaces/ComponentContainerInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorPowerOutputBonusTag,"Reactor.Bonus.PowerOutput","Reactor Bonus Power Output");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorFuelNeedBonusTag,"Reactor.Bonus.FuelNeed","Reactor Bonus Fuel Need");

// Sets default values
AReactorActor::AReactorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Reactor = CreateDefaultSubobject<UReactorAttributeSet>("Reactor Attributes");
	ComponentTag = ReactorComponentTag;
	StartTag = ReactorOnTag;
}

// Called when the game starts or when spawned
void AReactorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReactorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AReactorActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	UReactorDefinitionData * ReactorData = Cast<UReactorDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(ReactorPowerOutputBonusTag, ReactorData->PowerOutput));
		Values.Add(FCustomEffectValue(ReactorFuelNeedBonusTag, ReactorData->FuelNeed));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}
