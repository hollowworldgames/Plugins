// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Components/ViewPointComponent.h"

#include "Camera/CameraComponent.h"


// Sets default values for this component's properties
UViewPointComponent::UViewPointComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UViewPointComponent::MakeActive()
{
	if(Camera)
	{
		Camera->Activate();
	}
}

void UViewPointComponent::MakeInactive()
{
	if(Camera)
	{
		Camera->Deactivate();
	}
}

bool UViewPointComponent::IsActive()
{
	if(Camera)
	{
		return Camera->IsActive();
	}
	return false;
}


// Called when the game starts
void UViewPointComponent::BeginPlay()
{
	Super::BeginPlay();
	
	for(int x = 0;x < GetNumChildrenComponents();x++)
	{
		USceneComponent * Component = GetChildComponent(x);
		if(Component->IsA(UCameraComponent::StaticClass()))
		{
			Camera = Cast<UCameraComponent>(Component);
		}
	}
	
}


