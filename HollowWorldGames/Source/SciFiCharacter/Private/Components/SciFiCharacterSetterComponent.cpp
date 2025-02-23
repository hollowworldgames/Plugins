// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/SciFiCharacterSetterComponent.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorUseTag, "Combat.Skill.ArmorUse", "Armor Use");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorUseExperienceTag, "Combat.Skill.ArmorUse.Experience", "Armor Use Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PistolsTag, "Combat.Skill.Pistols", "Pistols");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PistolsExperienceTag, "Combat.Skill.Pistols.Experience", "Pistols Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RiflesTag, "Combat.Skill.Rifles", "Rifles");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RiflesExperienceTag, "Combat.Skill.Rifles.Experience", "RiflesExperiences");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PersonalShieldsTag, "Combat.Skill.PersonalShields", "Personal Shields");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PersonalShieldsExperienceTag, "Combat.Skill.PersonalShields.Experience", "Personal Shields Experience");

// Sets default values for this component's properties
USciFiCharacterSetterComponent::USciFiCharacterSetterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void USciFiCharacterSetterComponent::InitializeAttributes()
{
	Super::InitializeAttributes();
}

void USciFiCharacterSetterComponent::LoadFromDataComponent()
{
	Super::LoadFromDataComponent();
}

void USciFiCharacterSetterComponent::WriteToDataComponent()
{
	Super::WriteToDataComponent();
}


// Called when the game starts
void USciFiCharacterSetterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
