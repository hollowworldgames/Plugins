// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SpacePlayerState.h"
#include "Attributes/CombatAttributeSet.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Gameplay/SpaceCharacterShipAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Attributes/Professions/EngineerAttributeSet.h"
#include "Attributes/Professions/GunnerAttributeSet.h"
#include "Components/DataAccessComponent.h"
#include "Attributes/Professions/PilotAttributeSet.h"

ASpacePlayerState::ASpacePlayerState()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	VitalAttributes = CreateDefaultSubobject<UVitalAttributeSet>(TEXT("Vital Attributes"));
	CombatAttributes = CreateDefaultSubobject<UCombatAttributeSet>(TEXT("Combat Attributes"));
	ShipAttributes = CreateDefaultSubobject<USpaceCharacterShipAttributeSet>("Ship Attributes");
	PrimaryAttributes = CreateDefaultSubobject<UPrimaryAttributeSet>(TEXT("Primary Attributes"));
	ExperienceAttributes = CreateDefaultSubobject<UExperienceAttributeSet>(TEXT("Experience Attributes"));
	PilotAttributes = CreateDefaultSubobject<UPilotAttributeSet>(TEXT("Pilot Attributes"));
	GunnerAttributes = CreateDefaultSubobject<UGunnerAttributeSet>(TEXT("Gunner Attributes"));
	EngineerAttributes = CreateDefaultSubobject<UEngineerAttributeSet>(TEXT("Engineer Attributes"));
}

TObjectPtr<UGameplayAbilitySystemComponent> ASpacePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASpacePlayerState::InitAbilitySystem(APawn* MYPawn) 
{
	if (!ensure(AbilitySystemComponent) && !ensure(VitalAttributes)) return;
	AbilitySystemComponent->InitAbilityActorInfo(this, MYPawn);
	LoadAttributes();
	AbilitySystemComponent->ApplyGameplayEffects(Effects, VitalAttributes->GetLevel());
}

void ASpacePlayerState::LoadAttributes()
{
	if (UDataAccessComponent * DataAccess = GetComponentByClass<UDataAccessComponent>())
	{
		ExperienceAttributes->SetExperience(DataAccess->GetFloatAttribute(ExperienceTag.GetTag().ToString()));
		PrimaryAttributes->SetAgility(DataAccess->GetFloatAttribute(AgilityTag.GetTag().ToString()));
		PrimaryAttributes->SetPrecision(DataAccess->GetFloatAttribute(PrecisionTag.GetTag().ToString()));
		PrimaryAttributes->SetIntelligence(DataAccess->GetIntAttribute(IntelligenceTag.GetTag().ToString()));
		PrimaryAttributes->SetWisdom(DataAccess->GetFloatAttribute(WisdomTag.GetTag().ToString()));
		PrimaryAttributes->SetLuck(DataAccess->GetFloatAttribute(LuckTag.GetTag().ToString()));
		PrimaryAttributes->SetConstitution(DataAccess->GetFloatAttribute(ConstitutionTag.GetTag().ToString()));
		PrimaryAttributes->SetEndurance(DataAccess->GetFloatAttribute(EnduranceTag.GetTag().ToString()));
		PrimaryAttributes->SetCharisma(DataAccess->GetFloatAttribute(CharismaTag.GetTag().ToString()));
	}
}
