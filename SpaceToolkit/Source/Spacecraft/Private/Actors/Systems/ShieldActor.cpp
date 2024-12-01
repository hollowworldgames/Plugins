// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/ShieldActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Attributes/VitalAttributeSet.h"
#include "Attributes/Equipment/ShieldAttributeSet.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldHitPointsBonusTag,"Shield.Bonus.HitPoints","Shield Bonus Hit Points");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldPowerHitPointsBonusTag,"Shield.Bonus.PowerHitPoints","Shield Bonus Power To Hit Points");

// Sets default values
AShieldActor::AShieldActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ShieldAttributes = CreateDefaultSubobject<UShieldAttributeSet>(TEXT("ShieldAttributes"));
	StartTag = ShieldOnTag;
}

// Called when the game starts or when spawned
void AShieldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShieldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShieldActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	UShieldDefinitionData * ShieldData = Cast<UShieldDefinitionData>(SystemData);
	
	if(ensure(AbilitySystemComponent))
	{
		TArray<FCustomEffectValue> Values;
		Values.Add(FCustomEffectValue(ShieldHitPointsBonusTag, ShieldData->HitPoints));
		Values.Add(FCustomEffectValue(ShieldPowerHitPointsBonusTag, ShieldData->PowerToHitPoints));
		AbilitySystemComponent->ApplyGameplayEffect(InitializeEffect, VitalAttributes->GetLevel(), Values);	
	}
}

