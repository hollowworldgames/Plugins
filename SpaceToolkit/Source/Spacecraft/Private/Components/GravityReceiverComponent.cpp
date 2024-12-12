// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/GravityReceiverComponent.h"


// Sets default values for this component's properties
UGravityReceiverComponent::UGravityReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGravityReceiverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGravityReceiverComponent::ApplyGravityForce(FVector GravityForce)
{
	if (EnableGravity)
	{
		UPrimitiveComponent * Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		if(ensure(Root))
		{
			Root->AddForce(GravityForce, NAME_None, true);	
		}
	}
}


