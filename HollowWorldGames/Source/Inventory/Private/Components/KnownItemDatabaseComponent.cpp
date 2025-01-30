// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/KnownItemDatabaseComponent.h"


// Sets default values for this component's properties
UKnownItemDatabaseComponent::UKnownItemDatabaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

UObject* UKnownItemDatabaseComponent::GetItem(int64 ItemId)
{
	if (ItemId < 0)
	{
		return Items[ItemId];
	}
	else
	{
		return nullptr;
	}
}


// Called when the game starts
void UKnownItemDatabaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

