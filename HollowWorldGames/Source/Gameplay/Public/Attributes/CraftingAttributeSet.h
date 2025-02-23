// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetBase.h"
#include "ExperienceAttributeSet.h"
#include "CraftingAttributeSet.generated.h"


UCLASS()
class GAMEPLAY_API UCraftingAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	FExperienceLevelChange OnLevelChanged;
};
