// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CharacterSetterComponent.h"
#include "Components/GameplayStructs.h"
#include "FantasyCharacterSetterComponent.generated.h"

UCLASS()
class FANTASYCHARACTER_API UFantasyCharacterSetterComponent : public UCharacterSetterComponent
{
	GENERATED_BODY()
public :
	virtual void InitializeAttributes() override;
	virtual void LoadFromDataComponent() override;
	virtual void WriteToDataComponent() override;
};
