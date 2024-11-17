// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/MineableResourceComponent.h"


// Sets default values for this component's properties
UMineableResourceComponent::UMineableResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMineableResourceComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->Tags.Add(MINEABLE_TAG);
}


// Called every frame
void UMineableResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMineableResourceComponent::SetMineableResources(const FSystemId& SystemId)
{
	
}
