// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Components/ActorComponent.h"
#include "FantasyCraftingStationComponent.generated.h"

class UFantasyCraftingRecipe;
class ACharacter;
UE_DECLARE_GAMEPLAY_TAG_EXTERN(CraftingStationTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(CraftingStationCharacterTag);

class UGameItem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYCRAFTING_API UFantasyCraftingStationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyCraftingStationComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UGameItem* CraftItem(ACharacter * Character, UFantasyCraftingRecipe * Recipe);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
