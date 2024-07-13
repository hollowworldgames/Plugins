// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataAccessComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDataLoaded);

USTRUCT(BlueprintType)
struct FNumericValue
{
	GENERATED_BODY()
	UPROPERTY()
	float Value;
	bool Dirty = false;
	void SetValue(float NewValue);
};

USTRUCT(BlueprintType)
struct FStringValue
{
	GENERATED_BODY()
	UPROPERTY()
	FString Value;
	bool Dirty = false;
	void SetValue(FString NewValue);
};

USTRUCT(BlueprintType)
struct FRecord
{
	GENERATED_BODY()
	UPROPERTY()
	int RecordType = 0;
	UPROPERTY()
	TMap<FString, FNumericValue> NumericValues;
	UPROPERTY()
	TMap<FString, FStringValue> StringValues;
};



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DATAACCESS_API UDataAccessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDataAccessComponent();
	virtual void LoadActorState(uint64 ActorId);
	virtual void SaveActorState();
	FDataLoaded& GetDataLoaded() { return OnLoaded; }
	UFUNCTION(BlueprintCallable)
	float GetFloatAttribute(FString Attribute);
	UFUNCTION(BlueprintCallable)
	FString GetStringAttribute(FString Attribute);
	UFUNCTION(BlueprintCallable)
	int GetIntAttribute(FString Attribute);
	UFUNCTION(BlueprintCallable)
	float SetFloatAttribute(FString Attribute, float Value);
	UFUNCTION(BlueprintCallable)
	FString SetStringAttribute(FString Attribute, FString Value);
	UFUNCTION(BlueprintCallable)
	int SetIntAttribute(FString Attribute, int Value);
protected:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDataLoaded OnLoaded;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FString,FNumericValue> NumericAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FString,FStringValue> StringAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TArray<FRecord> Records;
};
