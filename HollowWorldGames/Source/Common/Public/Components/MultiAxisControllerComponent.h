// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MultiAxisControllerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMMON_API UMultiAxisControllerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMultiAxisControllerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
