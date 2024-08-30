// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataPlayerState.h"
#include "FantasyPlayerState.generated.h"

class UAbilitySystemComponent;
class URPGAttributeSet;
class UQuestReceiverComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerCharacterDead);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelChanged, float, NewLevel);

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerState : public ADataPlayerState
{
	GENERATED_BODY()
public :
	AFantasyPlayerState();
	UAbilitySystemComponent * GetAbilitySystemComponent() const { return AbilitySystemComponent; }
	UQuestReceiverComponent *  GetQuestComponent() const { return QuestReceiver; }
protected :
	UFUNCTION()
	void OnLevelChanged(float NewLevel);
	UFUNCTION()
	void OnDead();
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<URPGAttributeSet> Attributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UQuestReceiverComponent> QuestReceiver;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOnLevelChanged OnPlayerLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOnPlayerCharacterDead OnPlayerCharacterDead;
};
