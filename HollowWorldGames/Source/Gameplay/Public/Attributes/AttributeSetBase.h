// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
public :
	virtual float GetAttributeValue(FGameplayTag AttributeTag) { return 0; }
	bool HasAttribute(FGameplayTag Tag) const { return AttributeTags.HasTag(Tag); }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTagContainer AttributeTags;
};
