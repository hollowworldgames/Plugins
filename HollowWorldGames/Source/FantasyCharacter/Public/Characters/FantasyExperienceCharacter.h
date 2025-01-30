//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FantasyCombatCharacter.h"
#include "FantasyExperienceCharacter.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyExperienceCharacter : public AFantasyCombatCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyExperienceCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
