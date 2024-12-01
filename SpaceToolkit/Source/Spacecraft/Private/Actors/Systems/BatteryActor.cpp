// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/BatteryActor.h"

#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/BatteryAttributeSet.h"
#include "Interfaces/ComponentContainerInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(BatteryCapacityBonusTag,"Battery.Bonus.Capacity","Battery Capacity Bonus");
// Sets default values
ABatteryActor::ABatteryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BatteryAttributes = CreateDefaultSubobject<UBatteryAttributeSet>("Battery Attributes");
	ComponentTag = BatteryComponentTag;
}

// Called when the game starts or when spawned
void ABatteryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	UBatteryDefinitionData * BatteryData = Cast<UBatteryDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(BatteryCapacityBonusTag, BatteryData->BatteryCapacityBonus));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}

