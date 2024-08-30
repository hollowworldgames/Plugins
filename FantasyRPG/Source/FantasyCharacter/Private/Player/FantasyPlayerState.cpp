// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Player/FantasyPlayerState.h"
#include "Attributes/RPGAttributeSet.h"
#include "Components/FantasyQuestReceiverComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"

AFantasyPlayerState::AFantasyPlayerState()
{
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
	Attributes = CreateDefaultSubobject<URPGAttributeSet>("Attributes");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	QuestReceiver = CreateDefaultSubobject<UFantasyQuestReceiverComponent>("Quest Receiver");
}

void AFantasyPlayerState::OnLevelChanged(float NewLevel)
{
	OnPlayerLevelChanged.Broadcast(NewLevel);
}

void AFantasyPlayerState::OnDead()
{
	OnPlayerCharacterDead.Broadcast();
}

void AFantasyPlayerState::BeginPlay()
{
	Super::BeginPlay();
	Attributes->OnLevelChanged.AddDynamic(this, &AFantasyPlayerState::OnLevelChanged);
	Attributes->OnDead.AddDynamic(this, &AFantasyPlayerState::OnDead);
}
