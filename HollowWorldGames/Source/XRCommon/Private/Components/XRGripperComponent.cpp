// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/XRGripperComponent.h"


// Sets default values for this component's properties
UXRGripperComponent::UXRGripperComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UXRGripperComponent::Grip(const TScriptInterface<IGrippableInterface>& Grippable)
{
	
}

void UXRGripperComponent::Release()
{
	
}

// Called when the game starts
void UXRGripperComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UXRGripperComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

