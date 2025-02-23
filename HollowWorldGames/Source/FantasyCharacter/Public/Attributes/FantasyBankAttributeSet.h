// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "FantasyBankAttributeSet.generated.h"

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MoneyTag);

UCLASS()
class FANTASYCHARACTER_API UFantasyBankAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasyBankAttributeSet, Money);

	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Money, Category=Bank)
	FGameplayAttributeData Money;
	
	UFUNCTION()
	void OnRep_Money(const FGameplayAttributeData& OldMoney) const;

};
