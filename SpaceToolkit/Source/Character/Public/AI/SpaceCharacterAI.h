// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceCharacter.h"
#include "SpaceCharacterAI.generated.h"

class UCombatAttributeSet;
class UVitalAttributeSet;
class URPGAttributeSet;
class USpaceCharacterShipAttributeSet;
class UGameplayAbilitySystemComponent;

UCLASS(Blueprintable, BlueprintType)
class CHARACTER_API ASpaceCharacterAI : public ASpaceCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceCharacterAI();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetLevel(float Level);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UCombatAttributeSet> CombatAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	float Level = 1;
};
