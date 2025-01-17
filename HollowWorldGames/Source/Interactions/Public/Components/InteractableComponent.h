// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Interactable.h"
#include "Components/BoxComponent.h"
#include "InteractableComponent.generated.h"


class IInteractor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractNotify, ACharacter * , Character, UInteractableComponent * , Component);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONS_API UInteractableComponent : public UBoxComponent, public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();
	// Called every frame
	virtual void OnInteraction(TScriptInterface<IInteractor> interactor) override;
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void OnInteractComplete();
	FInteractNotify& GetOnBeginInteract() { return OnBeginInteract; }
	FInteractNotify& GetOnCompleteInteract() { return OnCompleteInteract; }
	FInteractNotify& GetOnInteractorEntered() { return OnInteractorEntered; }
	FInteractNotify& GetOnInteractorExited() { return OnInteractorExited; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual bool CanInteract(TScriptInterface<IInteractor> interactor);
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY()
	TScriptInterface<IInteractor> Interactor;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FInteractNotify OnBeginInteract;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FInteractNotify OnCompleteInteract;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FInteractNotify OnInteractorEntered;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FInteractNotify OnInteractorExited;
};
