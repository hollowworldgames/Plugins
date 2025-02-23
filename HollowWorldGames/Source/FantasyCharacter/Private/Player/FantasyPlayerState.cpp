//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/FantasyPlayerState.h"

#include "UtilityStatics.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/FantasyCombatAttributeSet.h"
#include "Attributes/FantasyVitalAttributeSet.h"
#include "Attributes/FantasySkillAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Components/CharacterSetterComponent.h"
#include "Components/EquipmentComponent.h"
#include "Components/FantasyCharacterSetterComponent.h"
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
	
	//Components
	QuestReceiver = CreateDefaultSubobject<UQuestReceiverComponent>("Quest Receiver");
	CharacterSetterComponent = CreateDefaultSubobject<UFantasyCharacterSetterComponent>("Character Setter");
	LooterComponent = CreateDefaultSubobject<UFantasyLooterComponent>("Looter Component");
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>("Equipment Component");
	//Skill Attributes
	CraftingAttributes = CreateDefaultSubobject<UFantasyCraftingAttributeSet>("Crafting Attributes");
	SkillAttributes = CreateDefaultSubobject<UFantasySkillAttributeSet>("Skill Attributes");
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
	//set player level here
}

void AFantasyPlayerState::LoadPrimaryAttributes(TArray<FCustomEffectValue>& Array)
{
	const float Strength = EquipmentComponent->GetAttributeFromGear(StrengthTag);
	Array.Add(FCustomEffectValue(StrengthAddendTag, DataAccessComponent->GetFloatAttribute(StrengthTag) + Strength));
	const float Agility = EquipmentComponent->GetAttributeFromGear(AgilityTag);
	Array.Add(FCustomEffectValue(AgilityAddendTag, DataAccessComponent->GetFloatAttribute(AgilityTag) + Agility));
	const float Precision = EquipmentComponent->GetAttributeFromGear(PrecisionTag);
	Array.Add(FCustomEffectValue(PrecisionAddendTag, DataAccessComponent->GetFloatAttribute(PrecisionTag) + Precision));
	const float Intelligence = EquipmentComponent->GetAttributeFromGear(IntelligenceTag);
	Array.Add(FCustomEffectValue(IntelligenceAddendTag, DataAccessComponent->GetFloatAttribute(IntelligenceTag) + Intelligence));
	const float Wisdom = EquipmentComponent->GetAttributeFromGear(WisdomTag);
	Array.Add(FCustomEffectValue(WisdomAddendTag, DataAccessComponent->GetFloatAttribute(WisdomTag) + Wisdom));
	const float Luck = EquipmentComponent->GetAttributeFromGear(LuckTag);
	Array.Add(FCustomEffectValue(LuckAddendTag, DataAccessComponent->GetFloatAttribute(LuckTag) + Luck));
	const float Constitution = EquipmentComponent->GetAttributeFromGear(ConstitutionTag);
	Array.Add(FCustomEffectValue(ConstitutionAddendTag, DataAccessComponent->GetFloatAttribute(ConstitutionTag) + Constitution));
	const float Endurance = EquipmentComponent->GetAttributeFromGear(EnduranceTag);
	Array.Add(FCustomEffectValue(EnduranceAddendTag, DataAccessComponent->GetFloatAttribute(EnduranceTag) + Endurance));
	const float Charisma = EquipmentComponent->GetAttributeFromGear(CharismaTag);
	Array.Add(FCustomEffectValue(CharismaAddendTag, DataAccessComponent->GetFloatAttribute(CharismaTag) + Charisma));
}

void AFantasyPlayerState::LoadVitalAttributes(TArray<FCustomEffectValue>& Array)
{
	const float MaxHealth = EquipmentComponent->GetAttributeFromGear(MaxHealthTag);
	Array.Add(FCustomEffectValue(MaxHealthTag, DataAccessComponent->GetFloatAttribute(MaxHealthTag) + MaxHealth));
	const float MaxEnergy = EquipmentComponent->GetAttributeFromGear(MaxEnergyTag);
	Array.Add(FCustomEffectValue(MaxEnergyTag, DataAccessComponent->GetFloatAttribute(MaxEnergyTag) + MaxEnergy));
	const float MaxMana = EquipmentComponent->GetAttributeFromGear(MaxManaTag);
	Array.Add(FCustomEffectValue(MaxManaTag, DataAccessComponent->GetFloatAttribute(MaxManaTag) + MaxMana));
}

void AFantasyPlayerState::LoadCombatAttributes(TArray<FCustomEffectValue>& Array)
{
	Array.Add(FCustomEffectValue(HitChanceTag, DataAccessComponent->GetFloatAttribute(HitChanceTag)));
	Array.Add(FCustomEffectValue(BlockChanceTag, DataAccessComponent->GetFloatAttribute(BlockChanceTag)));
	Array.Add(FCustomEffectValue(BlockValueTag, DataAccessComponent->GetFloatAttribute(BlockValueTag)));
	Array.Add(FCustomEffectValue(ParryChanceTag, DataAccessComponent->GetFloatAttribute(ParryChanceTag)));
	Array.Add(FCustomEffectValue(EvadeChanceTag, DataAccessComponent->GetFloatAttribute(EvadeChanceTag)));
	Array.Add(FCustomEffectValue(GlancingBlowChanceTag, DataAccessComponent->GetFloatAttribute(GlancingBlowChanceTag)));
	Array.Add(FCustomEffectValue(GlancingBlowValueTag, DataAccessComponent->GetFloatAttribute(GlancingBlowValueTag)));
	Array.Add(FCustomEffectValue(CriticalChanceTag, DataAccessComponent->GetFloatAttribute(CriticalChanceTag)));
	Array.Add(FCustomEffectValue(CriticalValueTag, DataAccessComponent->GetFloatAttribute(CriticalValueTag)));
	Array.Add(FCustomEffectValue(CriticalDefenseTag, DataAccessComponent->GetFloatAttribute(CriticalDefenseTag)));
}

void AFantasyPlayerState::LoadWeaponAttributes(TArray<FCustomEffectValue>& Array)
{
	
}

void AFantasyPlayerState::LoadMagicAttributes(TArray<FCustomEffectValue>& Array)
{
	
}


void AFantasyPlayerState::LoadCraftingAttributes(TArray<FCustomEffectValue>& Array)
{
	
}

void AFantasyPlayerState::InitializePlayerAttributes()
{

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
