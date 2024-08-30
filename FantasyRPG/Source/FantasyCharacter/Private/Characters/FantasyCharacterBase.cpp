// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Characters/FantasyCharacterBase.h"

#include "AbilitySystemBlueprintLibrary.h"
/*#include "Assets/ClassTableRow.h"
#include "Assets/SkillTableRow.h"
#include "Assets/CraftingSkillTableRow.h"*/
#include "Components/DataAccessComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/QuestReceiverComponent.h"
#include "GameFramework/PlayerState.h"


// Sets default values
AFantasyCharacterBase::AFantasyCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AFantasyCharacterBase::GetAbilitySystemComponent() const
{
	ensure(false);
	return nullptr;
}

// Called when the game starts or when spawned
void AFantasyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFantasyCharacterBase::ReadState()
{
	//UDataAccessComponent * DataAccessComponent = GetOwner()->GetComponentByClass<UDataAccessComponent>();
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	if(DataAccessComponent && AbilitySystemComponent)
	{
		//set Character level
		float Level = DataAccessComponent->GetFloatAttribute("Level");
		FString Class = DataAccessComponent->GetStringAttribute("Class");
		AbilitySystemComponent->SetLevel(Level);
		FString Context;
		/*FClassTableRow * ClassTableRow = ClassTable->FindRow<FClassTableRow>(FName(Class), Context);
		if(ensure(ClassTableRow))
		{
			//Set Primary Attributes
			AbilitySystemComponent->SetAttributeValue(StrengthTag, ClassTableRow->StrengthValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(AgilityTag, ClassTableRow->AgilityValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(PrecisionTag, ClassTableRow->PrecisionValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(IntelligenceTag, ClassTableRow->IntelligenceValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(WisdomTag, ClassTableRow->WisdomValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(LuckTag, ClassTableRow->LuckValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(ConstitutionTag, ClassTableRow->ConstitutionValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(EnduranceTag, ClassTableRow->EnduranceValue.GetValueAtLevel(Level));
			AbilitySystemComponent->SetAttributeValue(CharismaTag, ClassTableRow->CharismaValue.GetValueAtLevel(Level));
			//Calculate Secondary Attributes
			AbilitySystemComponent->ApplyGameplayEffect(ClassTableRow->CalculateSecondary,1);
			AbilitySystemComponent->ApplyGameplayEffect(ClassTableRow->SelfHeal, Level);

			AbilitySystemComponent->AddAbilities(ClassTableRow->ClassAbilities);

			//Set Character Skill Levels
			for(const FRecord& Record : DataAccessComponent->GetRecords())
			{
				switch(static_cast<EFantasyRecordType>(Record.RecordType))
				{
				case EFantasyRecordType::QuestRecord :
					{
						if(IsPlayerControlled() && GetPlayerState())
						{
							if(UQuestReceiverComponent * QuestReceiverComponent = GetPlayerState()->GetComponentByClass<UQuestReceiverComponent>())
							{
								QuestReceiverComponent->LoadQuestState(Record);
							}
						}
						break;
					}
				case EFantasyRecordType::SkillRecord :
					{
						float SkillLevel = Record.NumericValues["Level"].Value;
						AbilitySystemComponent->SetAttributeValue(Record.RecordTag, SkillLevel);
						FSkillTableRow * SkillTableRow = SkillTable->FindRow<FSkillTableRow>(Record.RecordTag.GetTagName(), Context);
						if(ensure(SkillTableRow))
						{
							AbilitySystemComponent->AddAbilities(SkillTableRow->Abilities, SkillLevel);
						}
						break;
					}
				case EFantasyRecordType::CraftingSkillRecord :
					{
						//Set Character Crafting Skill Levels
						float SkillLevel = Record.NumericValues["Level"].Value;
						AbilitySystemComponent->SetAttributeValue(Record.RecordTag, SkillLevel);
						FCraftingSkillTableRow * SkillTableRow = SkillTable->FindRow<FCraftingSkillTableRow>(Record.RecordTag.GetTagName(), Context);
						if(ensure(SkillTableRow))
						{
							AbilitySystemComponent->AddAbilities(SkillTableRow->Abilities, SkillLevel);
						}
						break;
					}
				default :
					{
						ensure(false);
						break;
					}
				}
			}
		}*/
	}
}

void AFantasyCharacterBase::WriteState()
{
}

// Called every frame
void AFantasyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

