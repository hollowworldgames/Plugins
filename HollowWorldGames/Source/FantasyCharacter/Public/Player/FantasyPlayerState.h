//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Actors/DataPlayerState.h"
#include "Components/GameplayStructs.h"
#include "FantasyPlayerState.generated.h"

class UFantasyCharacterSetterComponent;
class UFantasyMagicSkillAttributeSet;
class UFantasySkillAttributeSet;
class UEquipmentComponent;
class UInventoryComponent;
class UAbilitySystemComponent;
class UGameplayAbilitySystemComponent;
class UVitalAttributeSet;
class UPrimaryAttributeSet;
class URPGMeleeCombatAttributeSet;
class UExperienceAttributeSet;
class UQuestReceiverComponent;
class UCharacterSetterComponent;
class UFantasyLooterComponent;
class UFantasyBankAttributeSet;
class UFantasyCraftingAttributeSet;
/**
 * 
 */
UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerState : public ADataPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public :
	AFantasyPlayerState();
	
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	UQuestReceiverComponent * GetQuestReceiverComponent() const;
	void PlayerAlive();
protected :
	virtual void LoadPrimaryAttributes(TArray<FCustomEffectValue>& Array);
	virtual void LoadVitalAttributes(TArray<FCustomEffectValue>& Array);
	virtual void LoadCombatAttributes(TArray<FCustomEffectValue>& Array);
	virtual void LoadWeaponAttributes(TArray<FCustomEffectValue>& Array);
	virtual void LoadMagicAttributes(TArray<FCustomEffectValue>& Array);
	virtual void LoadCraftingAttributes(TArray<FCustomEffectValue>& Array);
	virtual void InitializePlayerAttributes();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UFUNCTION()
	void PlayerDead();
	//Gameplay
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AbilitySystem)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UPrimaryAttributeSet> PrimaryAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<URPGMeleeCombatAttributeSet> CombatAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UExperienceAttributeSet> ExperienceAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UFantasyBankAttributeSet> BankAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UFantasyCraftingAttributeSet> CraftingAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UFantasySkillAttributeSet> SkillAttributes;
	//Components	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UQuestReceiverComponent> QuestReceiver;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UFantasyCharacterSetterComponent> CharacterSetterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UFantasyLooterComponent> LooterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UInventoryComponent> InventoryComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UEquipmentComponent> EquipmentComponent;
};

