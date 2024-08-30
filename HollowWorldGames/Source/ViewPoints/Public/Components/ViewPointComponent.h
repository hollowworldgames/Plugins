// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/ViewPoint.h"
#include "Components/SceneComponent.h"
#include "ViewPointComponent.generated.h"


class UMotionControllerComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class  VIEWPOINTS_API UViewPointComponent : public USceneComponent, public IViewPoint
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UViewPointComponent();
	virtual void MakeActive() override;
	virtual void MakeInactive() override;
	virtual bool IsActive() override;
	bool IsMainViewPoint() const { return MainViewPoint; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, Category=Components)
	UCameraComponent * Camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	bool MainViewPoint = false;
};
