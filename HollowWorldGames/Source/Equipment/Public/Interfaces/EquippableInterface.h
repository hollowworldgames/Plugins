// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "EquippableInterface.generated.h"

class UEquipmentSlotComponent;
// This class does not need to be modified.
UINTERFACE(BlueprintType, NotBlueprintable)
class UEquippableInterface : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class EEquippableEffectType : uint8
{
	PercentageIncrease UMETA(DisplayName = "PercentageIncrease"),
	PercentageDecrease UMETA(DisplayName = "PercentageDecrease"),
	AmountIncrease UMETA(DisplayName = "AmountIncrease"),
	AmountDecrease UMETA(DisplayName = "AmountDecrease"),
};

USTRUCT(BlueprintType)
struct FEquipmentEffect
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Effect")
	FGameplayAttribute EffectedAttribute;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Effect")
	FGameplayTag AttributeTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Effect")
	EEquippableEffectType EffectType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Effect")
	float EffectAmount = 0.0f;
};

class EQUIPMENT_API IEquippableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = "Equippable", meta = (DisplayName = "Equip"))
	virtual void Equip_K2(UEquipmentSlotComponent * Component) { Equip(Component); }
	UFUNCTION(BlueprintCallable, Category = "Equippable", meta = (DisplayName = "Remove"))
	virtual void Remove_K2(UEquipmentSlotComponent * Component) { Remove(Component); }
	UFUNCTION(BlueprintCallable, Category = "Equippable", meta = (DisplayName = "Get Equipment Effects"))
	virtual TArray<FEquipmentEffect> GetEquipmentEffects_K2() { return GetEquipmentEffects(); }
	
	virtual USkeletalMesh * GetSkeletalMesh() const = 0;
	virtual void Equip(UEquipmentSlotComponent * Component) = 0;
	virtual void Remove(UEquipmentSlotComponent * Component) = 0;
	virtual bool CanBeUsedInSlot(FGameplayTag Slot) const = 0;
	virtual TArray<FEquipmentEffect> GetEquipmentEffects() const = 0;
	virtual float GetAttribute(FGameplayTag Tag) = 0;
};
