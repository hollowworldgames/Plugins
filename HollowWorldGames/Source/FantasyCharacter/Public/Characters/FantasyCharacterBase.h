//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataCharacter.h"
#include "GameFramework/Character.h"
#include "FantasyCharacterBase.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyCharacterBase : public ADataCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyCharacterBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float GetSpeed() const;
	float GetDirection() const;
	float GetTurn() const;
	virtual bool IsAlive() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
