// (c) Copyright 2024 Hollow World Games llc All Rights Reserved.


#include "Components/MappedInputComponent.h"

// Sets default values for this component's properties
UMappedInputComponent::UMappedInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMappedInputComponent::AddInputMappings(const UPlayerInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	
}

void UMappedInputComponent::RemoveInputMappings(const UPlayerInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	
}

void UMappedInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for (uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}



// Called when the game starts
void UMappedInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
