//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/FantasyPlayerState.h"

#include "UtilityStatics.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/FantasyCombatAttributeSet.h"
#include "Attributes/FantasyVitalAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Components/CharacterSetterComponent.h"
#include "Components/EquipmentComponent.h"
#include "Components/FantasyLooterComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/InventoryComponent.h"
#include "Components/QuestReceiverComponent.h"
#include "FantasyCrafting/Public/Attributes/FantasyCraftingAttributeSet.h"

AFantasyPlayerState::AFantasyPlayerState()
{
	//Gameplay
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("AbilitySystemComponent");
	VitalAttributes = CreateDefaultSubobject<UFantasyVitalAttributeSet>("Vital Attributes");
	PrimaryAttributes = CreateDefaultSubobject<UPrimaryAttributeSet>("Primary Attributes");
	CombatAttributes = CreateDefaultSubobject<UFantasyCombatAttributeSet>("Combat Attributes");
	ExperienceAttributes = CreateDefaultSubobject<UExperienceAttributeSet>("Experience Attributes");
	CraftingAttributes = CreateDefaultSubobject<UFantasyCraftingAttributeSet>("Crafting Attributes");
	//Components
	QuestReceiver = CreateDefaultSubobject<UQuestReceiverComponent>("Quest Receiver");
	CharacterSetterComponent = CreateDefaultSubobject<UCharacterSetterComponent>("Character Setter");
	LooterComponent = CreateDefaultSubobject<UFantasyLooterComponent>("Looter Component");
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>("Equipment Component");
}

UAbilitySystemComponent* AFantasyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UQuestReceiverComponent* AFantasyPlayerState::GetQuestReceiverComponent() const
{
	return QuestReceiver;
}

void AFantasyPlayerState::PlayerAlive()
{
	if (IsValidEnsure(AbilitySystemComponent))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
	}
	if (LooterComponent)
	{
		LooterComponent->BindOverlaps();
	}
}

void AFantasyPlayerState::PlayerDead()
{
	LooterComponent->UnbindOverlaps();
}

void AFantasyPlayerState::BeginPlay()
{
	Super::BeginPlay();
	VitalAttributes->OnDead.AddDynamic(this, &AFantasyPlayerState::PlayerDead);
}

void AFantasyPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
