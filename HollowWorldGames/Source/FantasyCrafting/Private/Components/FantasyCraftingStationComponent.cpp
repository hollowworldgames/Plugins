// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FantasyCraftingStationComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "UtilityStatics.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/InventoryComponent.h"
#include "Data/FantasyCraftingRecipe.h"
#include "FantasyCharacter/Public/Characters/FantasyCharacterBase.h"


UE_DEFINE_GAMEPLAY_TAG_COMMENT(CraftingStationTag, "Crafting.Station", "Crafting Station");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CraftingStationCharacterTag, "Crafting.Station.Character", "Character Crafting Station");

// Sets default values for this component's properties
UFantasyCraftingStationComponent::UFantasyCraftingStationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFantasyCraftingStationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFantasyCraftingStationComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UGameItem* UFantasyCraftingStationComponent::CraftItem(ACharacter* Character, UFantasyCraftingRecipe* Recipe)
{
	if (IsValidEnsure(Character))
	{
		const UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character));
		
		if (IsValidEnsure(Recipe) && IsValidEnsure(AbilitySystemComponent))
		{
			if (AbilitySystemComponent->GetAttributeValue(Recipe->CraftingAttributeRequired) >= Recipe->SkillLevel)
			{
				
			}
		}
	}
	return nullptr;
}

