// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SpacePlayerState.generated.h"

class UGameplayEffect;
class URPGAttributeSet;
class USpaceCharacterShipAttributeSet;
class USpaceCharacterAttributes;
class UGameplayAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class CHARACTER_API ASpacePlayerState : public APlayerState
{
	GENERATED_BODY()
public :
	ASpacePlayerState();
	TObjectPtr<UGameplayAbilitySystemComponent> GetAbilitySystemComponent() const;
	void InitAbilitySystem(APawn * MYPawn);
	TObjectPtr<URPGAttributeSet> GetRPGAttributeSet() const { return Attributes; }
protected :
	virtual void LoadAttributes();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<URPGAttributeSet> Attributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceCharacterShipAttributeSet> ShipAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	float Level = 1;
};
