// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SettingAsset.h"
#include "Engine/DataAsset.h"
#include "EnumSettingAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UEnumSettingAsset : public USettingAsset
{
	GENERATED_BODY()
public :
	int GetEnumValue() const;
	UFUNCTION()
	TArray<FString> GetEnumValues() const { return Enums; }
	virtual void Read(FXmlFile& File) override;
	virtual void Write(FXmlFile& File) override;
	virtual void Reset() override;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Enum)
	TArray<FString> Enums;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Enum, Meta = (GetOptions="GetEnumValues"))
	FString DefaultValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Enum, Meta = (GetOptions="GetEnumValues"))
	FString Value;
};
