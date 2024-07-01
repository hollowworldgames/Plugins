// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingAsset.h"
#include "IntSettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UIntSettingAsset : public USettingAsset
{
	GENERATED_BODY()
	public :
		int GetValue() const { return Value; }
	void SetValue(int NewValue);
	virtual void Reset() override { Value = DefaultValue; }
	virtual void Write(FXmlFile& File) override;
	virtual void Read(FXmlFile& File) override;
	protected :
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Setting)
	int Value = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	int DefaultValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	int MinValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	int MaxValue = 0;
};
