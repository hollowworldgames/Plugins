// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.
#include "NPC/FantasyNpcCharacter.h"

#include "Attributes/FantasyCombatAttributeSet.h"
#include "Attributes/FantasyVitalAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/CharacterSetterComponent.h"
#include "Components/FantasyLootComponent.h"

// Sets default values
AFantasyNpcCharacter::AFantasyNpcCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("AbilitySystemComponent");
	VitalAttributes = CreateDefaultSubobject<UFantasyVitalAttributeSet>("Vital Attributes");
	PrimaryAttributes = CreateDefaultSubobject<UPrimaryAttributeSet>("Primary Attributes");
	CombatAttributes = CreateDefaultSubobject<UFantasyCombatAttributeSet>("Combat Attributes");
	CharacterSetterComponent = CreateDefaultSubobject<UCharacterSetterComponent>("CharacterSetterComponent");
}

// Called when the game starts or when spawned
void AFantasyNpcCharacter::BeginPlay()
{
	Super::BeginPlay();
	VitalAttributes->OnDead.AddDynamic(this, &AFantasyNpcCharacter::CharacterDead);
}

// Called every frame
void AFantasyNpcCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AFantasyNpcCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AFantasyNpcCharacter::CharacterDead()
{
	if (LootComponent)
	{
		LootComponent->GenerateLoot();
	}
}

