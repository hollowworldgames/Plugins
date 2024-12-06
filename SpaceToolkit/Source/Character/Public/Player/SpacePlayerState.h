// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "SpacePlayerState.generated.h"

class UEngineerAttributeSet;
class UGunnerAttributeSet;
class UPilotAttributeSet;
class UExperienceAttributeSet;
class UGameplayEffect;
class URPGAttributeSet;
class UVitalAttributeSet;
class USpaceCombatAttributeSet;
class USpaceCharacterShipAttributeSet;
class USpaceCharacterAttributes;
class UGameplayAbilitySystemComponent;
class UPrimaryAttributeSet;
/**
 * 
 */
UCLASS()
class CHARACTER_API ASpacePlayerState : public ADataPlayerState
{
	GENERATED_BODY()
public :
	ASpacePlayerState();
	TObjectPtr<UGameplayAbilitySystemComponent> GetAbilitySystemComponent() const;
	void InitAbilitySystem(APawn * MYPawn);
protected :
	virtual void LoadAttributes();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceCharacterShipAttributeSet> ShipAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<class URPGCombatAttributeSet> CombatAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UPrimaryAttributeSet> PrimaryAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UPilotAttributeSet> PilotAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UGunnerAttributeSet> GunnerAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UEngineerAttributeSet> EngineerAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UExperienceAttributeSet> ExperienceAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=InitializeEffects)
	TArray<TSubclassOf<UGameplayEffect>> Effects;
};
