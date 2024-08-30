// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataCharacter.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Attributes/AttributeTags.h"
#include "FantasyCharacterBase.generated.h"


UENUM()
enum class EFantasyRecordType : uint8
{
	QuestRecord UMETA(DisplayName = "Quest Record"),
	SkillRecord UMETA(DisplayName = "Skill Record"),
	CraftingSkillRecord UMETA(DisplayName = "Crafting Skill Record")
};

UCLASS()
class FANTASYCHARACTER_API AFantasyCharacterBase : public ADataCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ReadState();
	void WriteState();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataTable> ClassTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataTable> SkillTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag StrengthTag = AttributeStrengthTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag AgilityTag = AttributeAgilityTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag PrecisionTag = AttributePrecisionTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag IntelligenceTag = AttributeIntelligenceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag WisdomTag = AttributeWisdomTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag LuckTag = AttributeLuckTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag ConstitutionTag = AttributeConstitutionTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag EnduranceTag = AttributeEnduranceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag CharismaTag = AttributeCharismaTag;
};
