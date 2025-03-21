﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/SystemActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Actors/SpaceCraftActor.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values
ASystemActor::ASystemActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(Root = CreateDefaultSubobject<USceneComponent>("Root"));
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	VitalAttributes = CreateDefaultSubobject<UVitalAttributeSet>("VitalAttributes");
}


UAbilitySystemComponent* ASystemActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASystemActor::InitializeAttributes(ASpaceCraftActor * SystemOwner, USystemDefinitionData * SystemData)
{
	Ship = SystemOwner;
	UGameplayAbilitySystemComponent * ShipAbilityComponent =
			Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Ship));
	if (ShipAbilityComponent)
	{
		ShipAbilityComponent->AddAbility(StartAbility, false);
		ShipAbilityComponent->AddAbility(StopAbility, false);
	}
	InitializeAttributes(SystemData);
	StartEffects(Ship);
}

void ASystemActor::InitializeAttributes(USystemDefinitionData* SystemData)
{
	if (ensure(AbilitySystemComponent) && ensure(SystemData))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, Ship);
		//add abilities
		AbilitySystemComponent->SetAttributeValue(LevelTag, SystemData->Level);
	}
}

void ASystemActor::StartEffects(ASpaceCraftActor * SystemOwner) const
{
	for (FSystemEffectToApply Apply : Effects)
	{
		UGameplayAbilitySystemComponent * System = SystemOwner->GetSystem(Apply.Component);
		if (ensure(System))
		{
			System->ApplyGameplayEffect(Apply.Effect, VitalAttributes->GetLevel(), this);
		}
	}
}

// Called when the game starts or when spawned
void ASystemActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASystemActor::IsOn_Implementation()
{
	if (AbilitySystemComponent)
	{
		return AbilitySystemComponent->HasTag(StartTag);
	}
	return false;
}

void ASystemActor::SetOn_Implementation(bool On)
{
	if (Ship)
	{
		UGameplayAbilitySystemComponent * ShipAbilityComponent =
			Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Ship));
		if (ShipAbilityComponent)
		{
			if(IsOn() && !On)
			{
				ShipAbilityComponent->OnAbilityInputPressed(StartAbility.Tag);
			}
			else if(!IsOn() && On)
			{
				ShipAbilityComponent->OnAbilityInputPressed(StopAbility.Tag);
			}
		}
	}
}
