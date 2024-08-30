// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/FantasyFixedDataComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values for this component's properties
UFantasyFixedDataComponent::UFantasyFixedDataComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyFixedDataComponent::LoadActorState(uint64 ActorId)
{
	Super::LoadActorState(ActorId);
	APawn * Pawn = GetOwner<APawn>();
	UGameplayAbilitySystemComponent * AbilitySystemComponent =
		Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	if(ensure(Pawn) && AbilitySystemComponent)
	{
		//set Character level
		AbilitySystemComponent->SetLevel(1);
		//Run Compute Attribute Effect
		//Run Compute Secondary Attributes Effect
		//Add Abilities
	}
}


// Called when the game starts
void UFantasyFixedDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

