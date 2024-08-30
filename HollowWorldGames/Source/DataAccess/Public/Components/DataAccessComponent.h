// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
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
	FGameplayTag RecordTag;
	UPROPERTY()
	int RecordType = 0;
	UPROPERTY()
	TMap<FString, FNumericValue> NumericValues;
	UPROPERTY()
	TMap<FString, FStringValue> StringValues;
	bool operator ==(const FRecord& Record) const { return RecordTag == Record.RecordTag; }
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
	virtual float SetFloatAttribute(FString Attribute, float Value);
	UFUNCTION(BlueprintCallable)
	virtual FString SetStringAttribute(FString Attribute, FString Value);
	UFUNCTION(BlueprintCallable)
	virtual int SetIntAttribute(FString Attribute, int Value);
	int GetCharacterId() const { return CharacterId; }
	TArray<FRecord> GetRecordsOfType(int Type) const;
	virtual void WriteRecord(FRecord& Record);
protected:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDataLoaded OnLoaded;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FString,FNumericValue> NumericAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FString,FStringValue> StringAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int CharacterId = 0;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TArray<FRecord> Records;
};
