// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingsGameInstance.h"
#include "FantasyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYDATABASE_API UFantasyGameInstance : public USettingsGameInstance
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	int GetSelectedCharacterId() const { return SelectedCharacterId; }
	UFUNCTION(BlueprintCallable)
	void SetSelectedCharacterId(int CharacterId) { SelectedCharacterId = CharacterId; }
protected :
	UPROPERTY()
	int SelectedCharacterId = 0;
};
