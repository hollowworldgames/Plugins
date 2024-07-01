// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SettingsGameInstance.generated.h"

class USettingAsset;

UCLASS()
class COMMON_API USettingsGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	void LoadSettings();
	UFUNCTION(BlueprintCallable)
	void SaveSettings();
	UFUNCTION(BlueprintCallable)
	void ResetSettings();
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TObjectPtr<USettingAsset>> Settings;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FString SettingsPath = "./Settings.xml";
};
