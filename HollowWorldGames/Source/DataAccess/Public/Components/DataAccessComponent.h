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
struct DATAACCESS_API FRecord
{
	GENERATED_BODY()
	UPROPERTY()
	FGameplayTag RecordTag;
	UPROPERTY()
	TMap<FGameplayTag, FNumericValue> NumericValues;
	UPROPERTY()
	TMap<FGameplayTag, FStringValue> StringValues;
	bool operator ==(const FRecord& Record) const { return RecordTag == Record.RecordTag; }
	float GetFloatValue(const FGameplayTag Tag) const;
	int GetIntValue(const FGameplayTag Tag) const;
	FName GetNameValue(const FGameplayTag Tag) const;
	FString GetStringValue(const FGameplayTag Tag) const;
	bool GetBoolValue(const FGameplayTag Tag) const { return GetIntValue(Tag) == 1; }
	void AddNumericValue(const FGameplayTag& Tag, int Value);
	void AddNumericValue(const FGameplayTag& Tag, float Value);
	void AddNumericValue(const FGameplayTag& Tag, bool Value);
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
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	float GetFloatAttribute(FGameplayTag Attribute);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	FString GetStringAttribute(FGameplayTag Attribute);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	FName GetNameAttribute(FGameplayTag Attribute);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	int GetIntAttribute(FGameplayTag Attribute);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	bool GetBoolAttribute(FGameplayTag Attribute);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	virtual float SetFloatAttribute(FGameplayTag Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	virtual FString SetStringAttribute(FGameplayTag Attribute, FString Value);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	virtual int SetIntAttribute(FGameplayTag Attribute, int Value);
	UFUNCTION(BlueprintCallable, Category="DataAccess")
	virtual bool SetBoolAttribute(FGameplayTag Attribute, bool Value);
	int GetCharacterId() const { return CharacterId; }
	TArray<FRecord> GetRecordsOfType(FGameplayTag Type) const;
	virtual void WriteRecord(FRecord& Record);
protected:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDataLoaded OnLoaded;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FGameplayTag,FNumericValue> NumericAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=DataCache)
	TMap<FGameplayTag,FStringValue> StringAttributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int CharacterId = 0;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TArray<FRecord> Records;
};


