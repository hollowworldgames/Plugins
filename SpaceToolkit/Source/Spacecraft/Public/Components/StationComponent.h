// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "StationComponent.generated.h"

class UInteractableComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACECRAFT_API UStationComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStationComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category="Components")
	TObjectPtr<UInteractableComponent> Interactor;
};
