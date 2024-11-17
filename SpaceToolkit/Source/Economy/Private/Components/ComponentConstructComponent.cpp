// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/ComponentConstructComponent.h"


FComponentConstructJob::FComponentConstructJob(FGameplayTag NewMaterial,
	TScriptInterface<IResourceSourceInterface> NewResourceSource,
	TScriptInterface<IMaterialSourceInterface> NewMaterialSource,
	TScriptInterface<IComponentSourceInterface> NewComponentSource,
	TScriptInterface<IEconomyCharacterInterface> NewCharacter, int NewQty)
{
	Material = NewMaterial;
	ResourceSource = NewResourceSource;
	MaterialSource = NewMaterialSource;
	ComponentSource = NewComponentSource;
	Character = NewCharacter;
	Qty = NewQty;
}

// Sets default values for this component's properties
UComponentConstructComponent::UComponentConstructComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UComponentConstructComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponentConstructComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Jobs.Num() > 0)
	{
		if (DoJob(Jobs[0]))
		{
			OnConstructed.Broadcast(this);
			Jobs.RemoveAt(0);
		}
	}
}

bool UComponentConstructComponent::StartConstruction(FGameplayTag Object,
	TScriptInterface<IResourceSourceInterface> ResourceSource,
	TScriptInterface<IComponentSourceInterface> ComponentSource,
	TScriptInterface<IMaterialSourceInterface> MaterialSource, TScriptInterface<IEconomyCharacterInterface> Character,
	int Qty)
{
	if (CanConstruct(Object, ResourceSource, ComponentSource, MaterialSource, Character, Qty) && Jobs.Num() < MaxJobs)
	{
		FComponentConstructJob Job(Object, ResourceSource,  MaterialSource,ComponentSource, Character, Qty);
		Jobs.Add(Job);
		CommitResources(Job);
		return true;
	}
	return false;
}

bool UComponentConstructComponent::CanConstruct(FGameplayTag Object,
	TScriptInterface<IResourceSourceInterface> ResourceSource,
	TScriptInterface<IComponentSourceInterface> ComponentSource,
	TScriptInterface<IMaterialSourceInterface> MaterialSource, TScriptInterface<IEconomyCharacterInterface> Character,
	int Qty)
{
	ensure(false);
	return false;
}

bool UComponentConstructComponent::DoJob(const FComponentConstructJob& Job)
{
	ensure(false);
	return false;
}

void UComponentConstructComponent::CommitResources(const FComponentConstructJob& ConstructJob)
{
	ensure(false);
}

