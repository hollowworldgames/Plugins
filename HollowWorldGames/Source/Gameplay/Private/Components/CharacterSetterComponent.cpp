// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterSetterComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "IPropertyTable.h"
#include "Attributes/AttributeTags.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/DataAccessComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Data/ClassDataRow.h"
#include "Data/ProfessionDataRow.h"
#include "Data/RaceDataRow.h"
#include "Interfaces/DataComponentInterface.h"


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
	if (FProfessionDataRow * Row = Professions->FindRow<FProfessionDataRow>(Profession, nullptr))
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
	Experience = NewExperience;
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
	{
		AbilitySystemComponent->SetAttributeValue(ExperienceTag, Experience);
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
		}
		
	}
}

void UCharacterSetterComponent::WriteToDataComponent()
{
	if (TScriptInterface<IDataComponentInterface> DataInterface = TObjectPtr<AActor>(GetOwner()))
	{
		if (UDataAccessComponent * DataComponent = DataInterface->GetDataAccessComponent())
		{
			DataComponent->SetFloatAttribute(LevelTag, Level);
			DataComponent->SetBoolAttribute(GenderTag, Gender.MatchesTag(MaleTag));
			DataComponent->SetStringAttribute(ClassTag, Class.ToString());
			DataComponent->SetStringAttribute(RaceTag, Race.ToString());
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

void UCharacterSetterComponent::InitializeAttributes() const
{
	if (FClassDataRow * Row = Classes->FindRow<FClassDataRow>(Class, nullptr))
	{
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
		{
			AbilitySystemComponent->ApplyGameplayEffects(Row->SecondaryEffects, 1);
		}
	}
}

void UCharacterSetterComponent::OnLevelChanged(float NewLevel)
{
	InitializeAttributes();
}

