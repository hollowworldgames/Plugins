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
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void LoadSettings();
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void SaveSettings();
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void ResetSettings();
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TObjectPtr<USettingAsset>> Settings;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FString SettingsPath = "./Settings.xml";
};
