// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "Attributes/AttributeTags.h"
#include "Components/ActorComponent.h"
#include "Components/GameplayStructs.h"
#include "CharacterSetterComponent.generated.h"

struct FClassDataRow;

USTRUCT(BlueprintType)
struct FAttributeTags
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Tags)
	FGameplayTag AttributeTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Tags)
	FGameplayTag AddendTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Tags)
	FGameplayTag MultiplierTag;
};


UCLASS(Abstract, BlueprintType)
class GAMEPLAY_API UCharacterSetterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterSetterComponent();
	UFUNCTION(BlueprintCallable, Category="Character")
	void SetLevel(const float NewLevel) const;
	UFUNCTION(BlueprintCallable, Category="Character")
	void SetClass(const FName NewClass);
	UFUNCTION(BlueprintCallable, Category="Character")
	void AddProfession(const FName Profession) const;
	UFUNCTION(BlueprintCallable, Category="Character")
	void SetRace(const FName NewRace);
	void SetGender(const FGameplayTag NewGender);
	
	void SetExperience(const float NewExperience);
	virtual void LoadFromDataComponent();
	virtual void WriteToDataComponent();
	float GetCharacterAttributeBonus(FGameplayTag Attribute) const;
	
	virtual void InitializeAttributes();
	FClassDataRow * GetClassDataRow() const;
	void SetCharacterToDefaults();
protected:
	virtual void LoadCraftingValues(TArray<FCustomEffectValue>& Array);
	virtual void LoadExperienceValues(TArray<FCustomEffectValue>& Array);
	virtual void LoadPrimaryValues(TArray<FCustomEffectValue>& Array);
	virtual void LoadVitalValues(TArray<FCustomEffectValue>& Array);
	virtual void LoadCombatValues(TArray<FCustomEffectValue>& Array);
	virtual void LoadSkillValues(TArray<FCustomEffectValue>& Array);
	UFUNCTION()
	void OnLevelChanged(const FGameplayAttribute& Attribute,float NewLevel);
	// Called when the game starts
	virtual void BeginPlay() override;
	void UpdateClass() const;
	void UpdateRace() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TObjectPtr<UDataTable> Classes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TObjectPtr<UDataTable> Professions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TObjectPtr<UDataTable> Races;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Settings")
	FGameplayTag Gender = MaleTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Settings")
	bool SetDefaults = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Settings")
	float Level = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Settings")
	float Experience = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FName Class;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FName Race;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	TArray<FName> StartingProfessions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FGameplayTagContainer ExperienceTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FGameplayTagContainer CombatTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FGameplayTagContainer SkillTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	FGameplayTagContainer CraftingSkillTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	TArray<FAttributeTags>	VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Settings")
	TArray<FAttributeTags>	PrimaryAttributes;
};
