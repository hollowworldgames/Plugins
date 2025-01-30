// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FantasyCombatCharacter.h"
#include "FantasyNpcCharacter.generated.h"

class UFantasyLootComponent;
class UVitalAttributeSet;
class UPrimaryAttributeSet;
class UCombatAttributeSet;
class UCharacterSetterComponent;

UCLASS()
class FANTASYCHARACTER_API AFantasyNpcCharacter : public AFantasyCombatCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyNpcCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	UFUNCTION()
	void CharacterDead();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UCharacterSetterComponent> CharacterSetterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UPrimaryAttributeSet> PrimaryAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TObjectPtr<UCombatAttributeSet> CombatAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UFantasyLootComponent> LootComponent;
};
