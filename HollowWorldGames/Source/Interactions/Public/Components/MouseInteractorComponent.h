// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MouseInteractorComponent.generated.h"


class UMouseInteractionComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseInteraction, AActor*, Actor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONS_API UMouseInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMouseInteractorComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AActor * GetActorUnderCursor(APlayerController * Controller) const;
	void Clear();
	UPROPERTY()
	TScriptInterface<class IHighlightable> Highlightable;
	UPROPERTY()
	TScriptInterface<class IInteractable> Interactable;
	UPROPERTY()
	TObjectPtr<UMouseInteractionComponent> Component;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FMouseInteraction RightClick;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FMouseInteraction LeftClick;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
