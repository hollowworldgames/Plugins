// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/MaterialRefinementComponent.h"

#include "Interface/EconomyCharacterInterface.h"

// Sets default values for this component's properties
UMaterialRefinementComponent::UMaterialRefinementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMaterialRefinementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMaterialRefinementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Jobs.Num() > 0)
	{
		if (DoJob(Jobs[0], DeltaTime))
		{
			OnMaterialRefined.Broadcast(this);
			Jobs[0].Character->OnMaterialRefined(Jobs[0].Material, Jobs[0].Qty);
			Jobs.RemoveAt(0);
		}
	}
}

void UMaterialRefinementComponent::StartRefinement(FGameplayTag Material,
	TScriptInterface<IResourceSourceInterface> ResourceSource, TScriptInterface<IMaterialSourceInterface> Destination,
	TScriptInterface<IEconomyCharacterInterface> Character, float Qty)
{
	if (CanRefine(Material, ResourceSource, Destination, Character, Qty) && Jobs.Num() < MaxJobs)
	{
		//verify material available
		const FRefineJob Job(Material, ResourceSource, Destination, Character, Qty);
		Jobs.Add(Job);
	}
}

bool UMaterialRefinementComponent::CanRefine(FGameplayTag Material,
	TScriptInterface<IResourceSourceInterface> ResourceSource, TScriptInterface<IMaterialSourceInterface> Destination,
	TScriptInterface<IEconomyCharacterInterface> Character, float Qty)
{
	ensure(false);
	return false; // Should be overriden as this component is Abstract Base Class
}

void UMaterialRefinementComponent::CommitResources(FRefineJob& Job)
{
	ensure(false);
	// Should be overriden as this component is Abstract Base Class
}

bool UMaterialRefinementComponent::DoJob(FRefineJob& Job, float DeltaTime)
{
	ensure(false);
	return false;// Should be overriden as this component is Abstract Base Class
}

