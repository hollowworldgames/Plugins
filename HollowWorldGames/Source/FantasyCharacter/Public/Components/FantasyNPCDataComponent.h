// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DataAccessComponent.h"
#include "FantasyNPCDataComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYCHARACTER_API UFantasyNPCDataComponent : public UDataAccessComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyNPCDataComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
