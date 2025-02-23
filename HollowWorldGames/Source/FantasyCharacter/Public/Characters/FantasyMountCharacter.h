// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FantasyCharacterBase.h"
#include "FantasyCombatCharacter.h"
#include "FantasyMountCharacter.generated.h"

class UInteractableComponent;

UCLASS()
class FANTASYCHARACTER_API AFantasyMountCharacter : public AFantasyCombatCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyMountCharacter();
	void Mount(ACharacter * Character);
	void Dismount();
	void SwitchToFlight() const;
	void SwitchToWalk() const;
	bool IsFlying() const;
protected:
	UFUNCTION()
	TArray<FName> GetSocketNames() const;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Rider)
	TObjectPtr<ACharacter> Rider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components, meta=(GetOptions="GetSocketNames"))
	FName Saddle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	TObjectPtr<UInteractableComponent> InteractionComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	bool CanFly = false;
};
