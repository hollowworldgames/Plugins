// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeChangedNotify, float, Value);

UCLASS()
class GAMEPLAY_API UGameplayWidgetController : public UObject
{
	GENERATED_BODY()
public :
	virtual void Initialize(ACharacter* NewCharacter);
	virtual void BindToAttributes();
	UFUNCTION(BlueprintCallable)
	virtual void PulseAttributes() {}
	virtual FName GetCharacterName() const;
protected :
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Character)
	TObjectPtr<ACharacter> Character;
};

