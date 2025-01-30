// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "AttributeSetBase.generated.h"

class UGameplayAbilitySystemComponent;


UCLASS()
class GAMEPLAY_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
public :
	virtual float GetAttributeValue(FGameplayTag AttributeTag) { return 0; }
	bool HasAttribute(FGameplayTag Tag) const { return AttributeTags.HasTag(Tag); }
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value);
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute);
	FAttributeChanged GetAttributeChanged() { return OnAttributeChanged;}
	void Initialize(UGameplayAbilitySystemComponent * AbilitySystemComponent, float Level, const TArray<FCustomEffectValue>& Attributes) const;
protected :
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTagContainer AttributeTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Events)
	FAttributeChanged OnAttributeChanged;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Effects)
	TSubclassOf<UGameplayEffect> InitializeEffect;
};

#define CHECK_IF_ATTRIBUTE(AttributeName, Attribute)\
	if(Attribute == Get##AttributeName##Attribute())\
	{\
		return AttributeName##Tag;\
	}

#define SET_IF_TAGMATCHES(TagName, AttributeTag, Value) \
if(AttributeTag.MatchesTag(TagName##Tag))\
{\
	Set##TagName(Value);\
	return;\
}

#define GET_IF_TAGMATCHES(TagName, AttributeTag)\
if(AttributeTag.MatchesTag(TagName##Tag))\
{\
	return Get##TagName();\
}
