//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Characters/FantasyCharacterBase.h"
#include "Interfaces/GameplayActorInterface.h"
#include "FantasyCombatCharacter.generated.h"

class UFloatVariableAsset;

UCLASS()
class FANTASYCHARACTER_API AFantasyCombatCharacter : public AFantasyCharacterBase, public IGameplayActorInterface, public IGenericTeamAgentInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyCombatCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual float GetAttributeBonus(FGameplayTag Attribute) override;
	virtual FAttributeChanged& GetAttributeChangedNotify() override;
	virtual TScriptInterface<IGameplayActorInterface> GetAbilityTarget() override;
	virtual float GetAttributeValue(FGameplayTag Attribute) override;
	virtual void ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, UGameplayAbilitySystemComponent * Source) override;
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	bool IsDead() const { return Dead; }
	virtual void OnDeath();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Team)
	int TeamID = 0;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Status)
	TScriptInterface<IGameplayActorInterface> AbilityTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
	bool Dead = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	TObjectPtr<UFloatVariableAsset> DestroyDelay;
};
