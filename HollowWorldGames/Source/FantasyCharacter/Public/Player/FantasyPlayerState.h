//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataPlayerState.h"
#include "FantasyPlayerState.generated.h"

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
class FANTASYCHARACTER_API AFantasyPlayerState : public ADataPlayerState
{
	GENERATED_BODY()
public :
	AFantasyPlayerState();
	UAbilitySystemComponent * GetAbilitySystemComponent() const;
	UQuestReceiverComponent * GetQuestReceiverComponent() const;
	void PlayerAlive();

protected :
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
	//Components	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UQuestReceiverComponent> QuestReceiver;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UCharacterSetterComponent> CharacterSetterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UFantasyLooterComponent> LooterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UInventoryComponent> InventoryComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UEquipmentComponent> EquipmentComponent;
};
