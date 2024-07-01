// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingAsset.h"
#include "BoolSettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UBoolSettingAsset : public USettingAsset
{
	GENERATED_BODY()
	public :
		bool GetValue() const { return Value; }
	void SetValue(bool NewValue);
	virtual void Reset() override { Value = DefaultValue; }
	virtual void Write(FXmlFile& File) override;
	virtual void Read(FXmlFile& File) override;
	protected :
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Setting)
	bool Value = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	bool DefaultValue = false;
};
