// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/AsteroidFieldComponent.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Data/Orbital.h"


// Sets default values for this component's properties
UAsteroidFieldComponent::UAsteroidFieldComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAsteroidFieldComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAsteroidFieldComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for(auto Component : AsteroidComponents)
	{
		if(Component.Value)
		{
			Component.Value->UnregisterComponent();
			Component.Value->DestroyComponent();
		}
	}
	AsteroidComponents.Empty();
}


// Called every frame
void UAsteroidFieldComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAsteroidFieldComponent::SetField(UAsteroidField* NewField)
{
	Field = NewField;
}

void UAsteroidFieldComponent::AddAsteroid(UFieldAsteroid* Asteroid)
{
	FTransform Transform(Asteroid->GetOrbitalLocation());
	Transform.SetRotation(Asteroid->GetOrbitalRotation().Quaternion());
	Transform.SetScale3D(Asteroid->GetOrbitalScale());
	UInstancedStaticMeshComponent * Component;
	if(AsteroidComponents.Contains(Asteroid->GetMesh()))
	{
		Component = *AsteroidComponents.Find(Asteroid->GetMesh());	
	}
	else
	{
		 Component = Cast<UInstancedStaticMeshComponent>(
			GetOwner()->AddComponentByClass(UInstancedStaticMeshComponent::StaticClass(),
				false, FTransform(), false ));
		if(ensure(Component))
		{
			AsteroidComponents.Add(Asteroid->GetMesh(), Component);
			Component->SetStaticMesh(Asteroid->GetMesh());
		}
	}
	Asteroid->SetInstanceId(Component->AddInstance(Transform, true));
	Asteroids.Add(Asteroid);
	OnAddAsteroid.Broadcast(Asteroid);
}


