// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/GalaxyActor.h"

#include "ConverterStatics.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneCaptureComponentCube.h"


// Sets default values
AGalaxyActor::AGalaxyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
	GalaxyDust = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Galaxy Dust"));
	GalaxyDust->SetupAttachment(RootComponent);
	GalaxyStars = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Galaxy Stars"));
	GalaxyStars->SetupAttachment(RootComponent);
	GalaxyCapture = CreateDefaultSubobject<USceneCaptureComponentCube>(TEXT("Galaxy Capture"));
	GalaxyCapture->SetupAttachment(RootComponent);
	GalaxyCapture->bCaptureEveryFrame = false;
	GalaxyCapture->bCaptureOnMovement = false;
	GalaxyBackground = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Galaxy Background"));
	GalaxyBackground->SetupAttachment(RootComponent);
	GalaxyBackground->SetWorldScale3D(FVector::One() * UConverterStatics::GmToUUnits(BackgroundDistanceGm));
}

// Called when the game starts or when spawned
void AGalaxyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGalaxyActor::SetBackgroundDistanceGm() const
{
	GalaxyBackground->SetWorldScale3D(FVector::One() * UConverterStatics::GmToUUnits(BackgroundDistanceGm));
}

// Called every frame
void AGalaxyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGalaxyActor::RenderGalaxy(const FSystemId SystemId, UGalaxyAsset* GalaxyAsset)
{
	//spawn region around location not including location
	//Spawn Dust particles
	for(int x = 0;x < GalaxyAsset->GetSize();x++)
	{
		for(int y = 0;y < GalaxyAsset->GetSize();y++)
		{
			float Density = GalaxyAsset->GetDensityScalar(x,y);
			if(Density > 0)
			{
				//Add Instance
				FTransform Transform;
				Transform.SetLocation(GalaxyAsset->GetDustLocation(x,y));
				int index = GalaxyDust->AddInstance(Transform, true);
				GalaxyDust->SetCustomDataValue(index,0, Density);
			}
		}
	}
	//Spawn Nebulae around us
	//render to cubemap
	GalaxyBackground->SetMaterial(0, BackgroundMaterial);
	GalaxyCapture->CaptureScene();
	GalaxyBackground->SetMaterial(0, GalaxyMaterial);
	GalaxyDust->ClearInstances();
	GalaxyStars->ClearInstances();
	for(USceneComponent * Component : NebulaeComponents)
	{
		Component->DestroyComponent();
	}
	NebulaeComponents.Empty();
}

