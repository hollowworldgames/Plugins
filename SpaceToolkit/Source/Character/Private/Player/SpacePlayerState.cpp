// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SpacePlayerState.h"

#include "Components/GameplayAbilitySystemComponent.h"
#include "Gameplay/SpaceCharacterAttributes.h"

ASpacePlayerState::ASpacePlayerState()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	Attributes = CreateDefaultSubobject<USpaceCharacterAttributes>("Attributes");
}

TObjectPtr<UGameplayAbilitySystemComponent> ASpacePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASpacePlayerState::InitAbilitySystem(APawn* MYPawn) 
{
	AbilitySystemComponent->InitAbilityActorInfo(this, MYPawn);
}
