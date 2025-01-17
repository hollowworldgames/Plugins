// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingAsset.h"
#include "CommonGameInstance.generated.h"

class UVariableAsset;
/**
 * 
 */
UCLASS()
class COMMON_API UCommonGameInstance : public UGameInstance
{
	GENERATED_BODY()
public :
	virtual void Init() override;
	virtual void Shutdown() override;
protected :
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void LoadSettings();
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void SaveSettings();
	UFUNCTION(BlueprintCallable, Category = "Settings Instance")
	void ResetSettings();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TObjectPtr<USettingAsset>> Settings;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Settings)
	FString SettingsPath;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Variables)
	TArray<TObjectPtr<UVariableAsset>> Variables;
};
