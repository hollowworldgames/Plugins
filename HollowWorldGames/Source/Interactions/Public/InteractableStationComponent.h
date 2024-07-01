// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "InteractableStationComponent.generated.h"


class UWidgetComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONS_API UInteractableStationComponent : public UBoxComponent, public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableStationComponent();
	virtual void OnInteraction(TScriptInterface<IInteractor> interactor) override;
	virtual class UCameraComponent * GetCamera();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category=Status)
	AActor * PreviousTarget = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category=Components)
	UWidgetComponent * Widget;
};
