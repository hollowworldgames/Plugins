// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/FantasyStandaloneDataAccessComponent.h"
#include "Records/CharacterRecord.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Assets/ClassTableRow.h"
#include "Assets/SkillTableRow.h"
#include "Components/FantasyQuestReceiverComponent.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "SQLLite/SQLLiteDataSubSystem.h"



// Sets default values for this component's properties
UFantasyStandaloneDataAccessComponent::UFantasyStandaloneDataAccessComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyStandaloneDataAccessComponent::LoadActorState(uint64 ActorId)
{
	Super::LoadActorState(ActorId);
	APawn * Pawn = GetOwner<APawn>();
	UGameplayAbilitySystemComponent * AbilitySystemComponent =
		Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	if(ensure(Pawn) && AbilitySystemComponent)
	{
		USQLLiteDataSubSystem * DataSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<USQLLiteDataSubSystem>();
		if(DataSubSystem)
		{
			FCharacterRecord CharacterRecord = DataSubSystem->GetCharacter(ActorId);
			TArray<FSkillRecord> Skills = DataSubSystem->GetCharacterSkills(ActorId);
			TArray<FQuestRecord> Quests = DataSubSystem->GetQuests(ActorId);
			FString Context;
			//Load Character Data
			NumericAttributes.Add("Level", FNumericValue(CharacterRecord.Level));
			StringAttributes.Add("Name", FStringValue(CharacterRecord.CharacterName));
			StringAttributes.Add("Class", FStringValue(CharacterRecord.Class.ToString()));
			NumericAttributes.Add("Location.X",FNumericValue(CharacterRecord.Location.X));
			NumericAttributes.Add("Location.Y",FNumericValue(CharacterRecord.Location.Y));
			NumericAttributes.Add("Location.Z",FNumericValue(CharacterRecord.Location.Z));
			NumericAttributes.Add("Gender",FNumericValue(static_cast<int>(CharacterRecord.Gender)));
			NumericAttributes.Add("Race", FNumericValue(CharacterRecord.Race));
			NumericAttributes.Add("World",FNumericValue(CharacterRecord.World));
			//Load Skill Data
			for(FSkillRecord& Skill : Skills)
			{
				FRecord SkillRecord;
				SkillRecord.RecordType = 0;
				SkillRecord.RecordTag = Skill.SkillId;
				SkillRecord.NumericValues["Level"] = FNumericValue(Skill.Level);
				SkillRecord.NumericValues["CharacterId"] = FNumericValue(Skill.CharacterId);
				Records.Add(SkillRecord);
			}
			//load Quest Data
			for(FQuestRecord Quest : Quests)
			{
				for(FQuestStageRecord Record : Quest.Stages)
				{
					FRecord QuestRecord;
					QuestRecord.RecordType = 1;
					QuestRecord.NumericValues["Quest"] = FNumericValue(Quest.QuestId);
					QuestRecord.NumericValues["Stage"] = FNumericValue(Record.StageId);
					QuestRecord.NumericValues["Count"] = FNumericValue(Record.Count);
					QuestRecord.NumericValues["Complete"] = FNumericValue(Record.Complete ? 1 : 0);
					QuestRecord.NumericValues["CharacterId"] = FNumericValue(Quest.CharacterId);
					Records.Add(QuestRecord);
				}
			}
			OnLoaded.Broadcast();
		}
	}
}

void UFantasyStandaloneDataAccessComponent::SaveActorState()
{
	Super::SaveActorState();
	
}

void UFantasyStandaloneDataAccessComponent::WriteRecord(FRecord& Record)
{
	Super::WriteRecord(Record);
}

float UFantasyStandaloneDataAccessComponent::SetFloatAttribute(FString Attribute, float Value)
{
	return Super::SetFloatAttribute(Attribute, Value);
}

FString UFantasyStandaloneDataAccessComponent::SetStringAttribute(FString Attribute, FString Value)
{
	return Super::SetStringAttribute(Attribute, Value);
}

int UFantasyStandaloneDataAccessComponent::SetIntAttribute(FString Attribute, int Value)
{
	return Super::SetIntAttribute(Attribute, Value);
}

// Called when the game starts
void UFantasyStandaloneDataAccessComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
