// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterSetterComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Attributes/AttributeTags.h"
#include "Attributes/CombatAttributeSet.h"
#include "Attributes/CraftingAttributeSet.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Attributes/SkillAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/DataAccessComponent.h"
#include "Components/EquipmentComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Data/ClassDataRow.h"
#include "Data/ProfessionDataRow.h"
#include "Data/RaceDataRow.h"
#include "Interfaces/DataComponentInterface.h"


class USkillAttributeSet;
// Sets default values for this component's properties
UCharacterSetterComponent::UCharacterSetterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCharacterSetterComponent::SetLevel(const float NewLevel) const
{
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
	{
		AbilitySystemComponent->SetAttributeValue(LevelTag, Level);
	}
}


// Called when the game starts
void UCharacterSetterComponent::BeginPlay()
{
	Super::BeginPlay();

	if (SetDefaults)
	{
		SetLevel(Level);
		UpdateClass();
		UpdateRace();
		for (FName Profession : StartingProfessions)
		{
			AddProfession(Profession);
		}
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
            			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
        {
            UExperienceAttributeSet * ExperienceAttributeSet = Cast<UExperienceAttributeSet>(
            	AbilitySystemComponent->GetAttributeSet(UExperienceAttributeSet::StaticClass()));
        	if (ExperienceAttributeSet)
        	{
        		ExperienceAttributeSet->OnLevelChanged.AddDynamic(this, &UCharacterSetterComponent::OnLevelChanged);
        	}
        }
	}
	
}

void UCharacterSetterComponent::UpdateClass() const
{
	if (FClassDataRow * Row = Classes->FindRow<FClassDataRow>(Class, nullptr))
	{
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
		{
			AbilitySystemComponent->ApplyGameplayEffects(Row->InitialEffects, 1);
			AbilitySystemComponent->ApplyGameplayEffects(Row->SecondaryEffects, 1);
			AbilitySystemComponent->AddAbilities(Row->Abilities);
		}
	}
}

void UCharacterSetterComponent::SetClass(const FName NewClass)
{
	Class = NewClass;
	UpdateClass();
}

void UCharacterSetterComponent::AddProfession(const FName Profession) const
{
	if (const FProfessionDataRow * Row = Professions->FindRow<FProfessionDataRow>(Profession, nullptr))
	{
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
		{
			AbilitySystemComponent->ApplyGameplayEffects(Row->InitialEffects, 1);
			AbilitySystemComponent->AddAbilities(Row->Abilities);
		}
	}
}

void UCharacterSetterComponent::UpdateRace() const
{
	if (FRaceDataRow * Row = Races->FindRow<FRaceDataRow>(Race, nullptr))
	{
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
		{
			AbilitySystemComponent->ApplyGameplayEffects(Row->InitialEffects, 1);
			AbilitySystemComponent->AddAbilities(Row->Abilities);
		}
	}
}

void UCharacterSetterComponent::SetRace(const FName NewRace)
{
	Race = NewRace;
	UpdateRace();
}

void UCharacterSetterComponent::SetGender(const FGameplayTag NewGender)
{
	Gender = NewGender;
}

void UCharacterSetterComponent::SetExperience(const float NewExperience)
{
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
	{
		Experience = NewExperience;
		if (const UExperienceAttributeSet * ExperienceAttributes = Cast<UExperienceAttributeSet>(AbilitySystemComponent->GetAttributeSet(UExperienceAttributeSet::StaticClass())))
		{
			TArray<FCustomEffectValue> EffectValues;
			EffectValues.Add(FCustomEffectValue(ExperienceTag, Experience));
			LoadExperienceValues(EffectValues);
			ExperienceAttributes->Initialize(AbilitySystemComponent, 1, EffectValues);
		}
	}
}

void UCharacterSetterComponent::LoadFromDataComponent()
{
	if (TScriptInterface<IDataComponentInterface> DataInterface = TObjectPtr<AActor>(GetOwner()))
	{
		if (UDataAccessComponent * DataComponent = DataInterface->GetDataAccessComponent())
		{
			Gender = (DataComponent->GetBoolAttribute(GenderTag)) ? MaleTag : FemaleTag;
			SetLevel(DataComponent->GetFloatAttribute(LevelTag));
			SetClass(FName(DataComponent->GetStringAttribute(ClassTag)));
			SetRace(FName(DataComponent->GetStringAttribute(RaceTag)));
			SetExperience(DataComponent->GetFloatAttribute(ExperienceTag));
			TArray<FRecord> Records = DataComponent->GetRecordsOfType(ProfessionTag);
			for (FRecord Record : Records)
			{
				AddProfession(Record.GetNameValue(ProfessionTag));
			}
			if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
             						UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
            {
             	UExperienceAttributeSet * ExperienceAttributeSet = Cast<UExperienceAttributeSet>(
             		AbilitySystemComponent->GetAttributeSet(UExperienceAttributeSet::StaticClass()));
             	if (ExperienceAttributeSet)
             	{
             		ExperienceAttributeSet->OnLevelChanged.AddDynamic(this, &UCharacterSetterComponent::OnLevelChanged);
             	}
            }
			InitializeAttributes();
		}
		
	}
}

void UCharacterSetterComponent::WriteToDataComponent()
{
	const UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
									 UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	if (!AbilitySystemComponent)
	{
		return;
	}
	
	if (const TScriptInterface<IDataComponentInterface> DataInterface = TObjectPtr<AActor>(GetOwner()))
	{
		if (UDataAccessComponent * DataComponent = DataInterface->GetDataAccessComponent())
		{
			DataComponent->SetFloatAttribute(LevelTag, Level);
			DataComponent->SetFloatAttribute( ExperienceTag, AbilitySystemComponent->GetAttributeValue(ExperienceTag));
			DataComponent->SetBoolAttribute(GenderTag, Gender.MatchesTag(MaleTag));
			DataComponent->SetStringAttribute(ClassTag, Class.ToString());
			DataComponent->SetStringAttribute(RaceTag, Race.ToString());
			for (const auto Tag : SkillTags)
			{
				DataComponent->SetFloatAttribute( Tag, AbilitySystemComponent->GetAttributeValue(Tag));
			}
			for (const auto Tag : CraftingSkillTags)
			{
				DataComponent->SetFloatAttribute( Tag, AbilitySystemComponent->GetAttributeValue(Tag));
			}
			DataComponent->SaveActorState();
		}
	}
}

float UCharacterSetterComponent::GetCharacterAttributeBonus(FGameplayTag Attribute) const
{
	const FClassDataRow * ClassRow = Classes->FindRow<FClassDataRow>(Class, nullptr);
	const FRaceDataRow * RaceRow = Races->FindRow<FRaceDataRow>(Race, nullptr);
	if (ClassRow && RaceRow)
	{
		if (Attribute.MatchesTag(StrengthTag))
		{
			return ClassRow->StrengthBonus + RaceRow->StrengthBonus;
		}
		if (Attribute.MatchesTag(AgilityTag))
		{
			return ClassRow->AgilityBonus + RaceRow->AgilityBonus;
		}
		if (Attribute.MatchesTag(PrecisionTag))
		{
			return ClassRow->PrecisionBonus + RaceRow->PrecisionBonus;
		}
		if (Attribute.MatchesTag(WisdomTag))
		{
			return ClassRow->WisdomBonus + RaceRow->WisdomBonus;
		}
		if (Attribute.MatchesTag(IntelligenceTag))
		{
			return ClassRow->IntelligenceBonus + RaceRow->IntelligenceBonus;
		}
		if (Attribute.MatchesTag(ConstitutionTag))
		{
			return ClassRow->ConstitutionBonus + RaceRow->ConstitutionBonus;
		}
		if (Attribute.MatchesTag(EnduranceTag))
		{
			return ClassRow->EnduranceBonus + RaceRow->EnduranceBonus;
		}
		if (Attribute.MatchesTag(CharismaTag))
		{
			return ClassRow->CharismaBonus + RaceRow->Charisma;
		}
	}
	return 1.0f;
}

void UCharacterSetterComponent::InitializeAttributes()
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));

	if (!AbilitySystemComponent)
		return;

	if (const UPrimaryAttributeSet * PrimaryAttributeSet = Cast<UPrimaryAttributeSet>(AbilitySystemComponent->GetAttributeSet(UPrimaryAttributeSet::StaticClass())))
	{
		TArray<FCustomEffectValue> PrimaryValues;
		LoadPrimaryValues(PrimaryValues);
		PrimaryAttributeSet->Initialize(AbilitySystemComponent, Level, PrimaryValues);
	}

	if (const UVitalAttributeSet * VitalAttributeSet = Cast<UVitalAttributeSet>(AbilitySystemComponent->GetAttributeSet(UVitalAttributeSet::StaticClass())))
	{
		TArray<FCustomEffectValue> VitalValues;
		LoadVitalValues(VitalValues);
		VitalAttributeSet->Initialize(AbilitySystemComponent, Level, VitalValues);
	}

	if (const UCombatAttributeSet * CombatAttributeSet = Cast<UCombatAttributeSet>(AbilitySystemComponent->GetAttributeSet(UCombatAttributeSet::StaticClass())))
	{
		TArray<FCustomEffectValue> CombatValues;
		LoadCombatValues(CombatValues);
		CombatAttributeSet->Initialize(AbilitySystemComponent, Level, CombatValues);
	}

	TArray<UAttributeSetBase*> SkillAttributeSets;

	AbilitySystemComponent->GetAllAttributeSets(SkillAttributeSets, USkillAttributeSet::StaticClass());
	AbilitySystemComponent->GetAllAttributeSets(SkillAttributeSets, UCraftingAttributeSet::StaticClass());
	TArray<FCustomEffectValue> SkillValues;
	LoadSkillValues(SkillValues);
	LoadCraftingValues(SkillValues);
	for (auto Set : SkillAttributeSets)
	{
		if (Set)
		{
			Set->Initialize(AbilitySystemComponent, Level, SkillValues);
		}
	}
			
	if (const FClassDataRow * Row = Classes->FindRow<FClassDataRow>(Class, nullptr))
	{
		AbilitySystemComponent->ApplyGameplayEffects(Row->SecondaryEffects, 1);
	}
}

FClassDataRow* UCharacterSetterComponent::GetClassDataRow() const
{
	if (IsValidEnsure(Classes))
	{
		return Classes->FindRow<FClassDataRow>(Class, nullptr);
	}
	return nullptr;
}

void UCharacterSetterComponent::SetCharacterToDefaults()
{
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(DataAccessComponent))
	{
		return;
	}
	
	if (const FClassDataRow * Row = Classes->FindRow<FClassDataRow>(Class, nullptr))
	{
		for (auto Skill : Row->InitialSkillValues)
		{
			DataAccessComponent->SetFloatAttribute(Skill.Key, Skill.Value);	
		}
	}
	DataAccessComponent->SaveActorState();
	LoadFromDataComponent();
}

void UCharacterSetterComponent::LoadCraftingValues(TArray<FCustomEffectValue>& Array)
{
	UEquipmentComponent * EquipmentComponent = GetOwner()->FindComponentByClass<UEquipmentComponent>();
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(EquipmentComponent) || !IsValidEnsure(DataAccessComponent))
	{
		return;
	}
	
	for (auto Tag : CraftingSkillTags)
	{
		Array.Add(FCustomEffectValue(Tag, DataAccessComponent->GetFloatAttribute(Tag)));
	}
}

void UCharacterSetterComponent::LoadExperienceValues(TArray<FCustomEffectValue>& Array)
{
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(DataAccessComponent))
	{
		return;
	}
	
	for (const auto Tag : ExperienceTags)
	{
		Array.Add(FCustomEffectValue(Tag, DataAccessComponent->GetFloatAttribute(Tag)));
	}
}

void UCharacterSetterComponent::LoadPrimaryValues(TArray<FCustomEffectValue>& Array)
{
	UEquipmentComponent * EquipmentComponent = GetOwner()->FindComponentByClass<UEquipmentComponent>();
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(EquipmentComponent) || !IsValidEnsure(DataAccessComponent))
	{
		return;
	}

	for (const auto Tags : PrimaryAttributes)
	{
		const float Value = EquipmentComponent->GetAttributeFromGear(Tags.AttributeTag);
		Array.Add(FCustomEffectValue(Tags.AddendTag, DataAccessComponent->GetFloatAttribute(Tags.AttributeTag) + Value));
		Array.Add(FCustomEffectValue(Tags.MultiplierTag, GetCharacterAttributeBonus(Tags.AttributeTag)));
	}
}

void UCharacterSetterComponent::LoadVitalValues(TArray<FCustomEffectValue>& Array)
{
	UEquipmentComponent * EquipmentComponent = GetOwner()->FindComponentByClass<UEquipmentComponent>();
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(EquipmentComponent) || !IsValidEnsure(DataAccessComponent))
	{
		return;
	}

	for (const auto Tags : VitalAttributes)
	{
		const float Value = EquipmentComponent->GetAttributeFromGear(Tags.AttributeTag);
		Array.Add(FCustomEffectValue(Tags.AddendTag, DataAccessComponent->GetFloatAttribute(Tags.AttributeTag) + Value));
		Array.Add(FCustomEffectValue(Tags.MultiplierTag, GetCharacterAttributeBonus(Tags.AttributeTag)));
	}
}

void UCharacterSetterComponent::LoadCombatValues(TArray<FCustomEffectValue>& Array)
{
	UEquipmentComponent * EquipmentComponent = GetOwner()->FindComponentByClass<UEquipmentComponent>();
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(EquipmentComponent) || !IsValidEnsure(DataAccessComponent))
	{
		return;
	}

	for (auto Tag : CombatTags)
	{
		const float Value = EquipmentComponent->GetAttributeFromGear(Tag);
		Array.Add(FCustomEffectValue(Tag, DataAccessComponent->GetFloatAttribute(Tag) + Value));
	}
}

void UCharacterSetterComponent::LoadSkillValues(TArray<FCustomEffectValue>& Array)
{
	UDataAccessComponent * DataAccessComponent = GetOwner()->FindComponentByClass<UDataAccessComponent>();
	if (!IsValidEnsure(DataAccessComponent))
	{
		return;
	}
	
	for (const auto Tag : SkillTags)
	{
		Array.Add(FCustomEffectValue(Tag, DataAccessComponent->GetFloatAttribute(Tag)));
	}
}

void UCharacterSetterComponent::OnLevelChanged(const FGameplayAttribute& Attribute, float NewLevel)
{
	if (Attribute == UExperienceAttributeSet::GetLevelAttribute())
	{
		InitializeAttributes();
	}
}

