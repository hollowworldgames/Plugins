// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingAsset.h"
#include "StringSettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UStringSettingAsset : public USettingAsset
{
	GENERATED_BODY()
public :
	FString GetValue() const { return Value; }
	void SetValue(FString NewValue);
	virtual void Reset() override { Value = DefaultValue; }
	virtual void Write(FXmlFile& File) override;
	virtual void Read(FXmlFile& File) override;
	protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Setting)
	FString Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	FString DefaultValue;
};
