// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MouseInteractionComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseInteract, AActor*, Interactor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONS_API UMouseInteractionComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMouseInteractionComponent();
	void RightMouseUp(AActor * Interactor) const;
	void RightMouseDown(AActor * Interactor) const;
	void LeftMouseUp(AActor * Interactor) const;
	void LeftMouseDown(AActor * Interactor) const;
	void MouseEntered(AActor * Interactor) const;
	void MouseLeft(AActor * Interactor);
	void SetLeftMouse(bool State, AActor* Interactor);
	void SetRightMouse(bool State, AActor* Interactor);
protected:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnMouseEntered;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnMouseLeave;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnRightMouseUp;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnRightMouseDown;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnLeftMouseUp;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FMouseInteract OnLeftMouseDown;
	bool LeftMouse = false;
	bool RightMouse = false;
};
