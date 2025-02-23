// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CharacterSetterComponent.h"
#include "SciFiCharacterSetterComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SCIFICHARACTER_API USciFiCharacterSetterComponent : public UCharacterSetterComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	USciFiCharacterSetterComponent();
	virtual void InitializeAttributes() override;
	virtual void LoadFromDataComponent() override;
	virtual void WriteToDataComponent() override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
