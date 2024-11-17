// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GalaxyAsset.h"
#include "GameFramework/Actor.h"
#include "GalaxyActor.generated.h"

UCLASS()
class GALAXY_API AGalaxyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGalaxyActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void RenderGalaxy(const FSystemId SystemId, UGalaxyAsset* GalaxyAsset);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UInstancedStaticMeshComponent> GalaxyDust;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UInstancedStaticMeshComponent> GalaxyStars;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USceneCaptureComponentCube> GalaxyCapture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UTextureRenderTargetCube> GalaxyRenderTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UStaticMeshComponent> GalaxyBackground;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Materials)
	TObjectPtr<UMaterialInterface> BackgroundMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Materials)
	TObjectPtr<UMaterialInterface> GalaxyMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Materials)
	TArray<TObjectPtr<USceneComponent>> NebulaeComponents;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings, Interp)
	double BackgroundDistanceGm = 10;
	UFUNCTION(CallInEditor)
	void SetBackgroundDistanceGm() const;
};
