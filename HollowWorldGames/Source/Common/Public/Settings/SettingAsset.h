// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "XmlFile.h"
#include "Engine/DataAsset.h"
#include "SettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API USettingAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	FName GetSettingName() const { return SettingName; }
	FName GetSettingCategory() const { return Category; }
	virtual void Read(FXmlFile& File);
	virtual void Write(FXmlFile& File);
	virtual void Reset();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	FName SettingName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	FName Category;
};
