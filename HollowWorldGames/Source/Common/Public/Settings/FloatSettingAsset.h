// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingAsset.h"
#include "FloatSettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UFloatSettingAsset : public USettingAsset
{
	GENERATED_BODY()
public:
	float GetValue() const { return Value; }
	void SetValue(float NewValue);
	virtual void Reset() override { Value = DefaultValue; }
	virtual void Write(FXmlFile& File) override;
	virtual void Read(FXmlFile& File) override;
	protected :
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Setting)
	float Value = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	float DefaultValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	float MinValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	float MaxValue = 0;
};
