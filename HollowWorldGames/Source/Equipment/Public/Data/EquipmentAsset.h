// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GameItemTemplate.h"
#include "Engine/DataAsset.h"
#include "Interfaces/EquippableInterface.h"
#include "EquipmentAsset.generated.h"

UCLASS(BlueprintType)
class EQUIPMENT_API UEquipmentItem : public UGameItem, public IEquippableInterface
{
	GENERATED_BODY()
public:
	virtual USkeletalMesh * GetSkeletalMesh() const;
	virtual void Equip(UEquipmentSlotComponent * Component);
	virtual void Remove(UEquipmentSlotComponent * Component);
	virtual bool CanBeUsedInSlot(FGameplayTag Slot) const;
	virtual TArray<FEquipmentEffect> GetEquipmentEffects() const;
	virtual float GetAttribute(FGameplayTag Tag);
protected :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TArray<FEquipmentEffect> EquipmentEffects;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	FGameplayTagContainer EquipmentSlots;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TObjectPtr<USkeletalMesh> Mesh;
	friend class UEquipmentAsset;
};

UCLASS()
class EQUIPMENT_API UEquipmentAsset : public UGameItemTemplate
{
	GENERATED_BODY()
public :
	virtual UGameItem * CreateInstance(UObject* Outer) const override;
protected :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TArray<FEquipmentEffect> EquipmentEffects;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	FGameplayTagContainer EquipmentSlots;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TObjectPtr<USkeletalMesh> Mesh;
};


