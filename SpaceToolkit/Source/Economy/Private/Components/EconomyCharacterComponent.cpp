// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/EconomyCharacterComponent.h"

#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values for this component's properties
UEconomyCharacterComponent::UEconomyCharacterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UEconomyCharacterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEconomyCharacterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UEconomyCharacterComponent::CanRefine(FGameplayTag Material)
{
	UGameplayAbilitySystemComponent * GameplayComponent = GetOwner()->GetComponentByClass<UGameplayAbilitySystemComponent>();
	if (ensure(GameplayComponent))
	{
		return GameplayComponent->GetAttributeValue(Material) > 0;
	}
	return false;
}

bool UEconomyCharacterComponent::CanConstruct(FGameplayTag Object, float Level)
{
	UGameplayAbilitySystemComponent * GameplayComponent = GetOwner()->GetComponentByClass<UGameplayAbilitySystemComponent>();
	if (ensure(GameplayComponent))
	{
		return GameplayComponent->GetAttributeValue(Object) >= Level;
	}
	return false;
}

TArray<FGameplayTag> UEconomyCharacterComponent::GetRefinableMaterials()
{
	TArray<FGameplayTag> Materials;
	for (FGameplayTag Tag : RefinableMaterials)
	{
		Materials.Add(Tag);
	}
	return Materials;
}

TArray<FGameplayTag> UEconomyCharacterComponent::GetConstructableObjects()
{
	TArray<FGameplayTag> Construct;
	for (FGameplayTag Tag : ConstructableObjects)
	{
		Construct.Add(Tag);
	}
	return Construct;
}
