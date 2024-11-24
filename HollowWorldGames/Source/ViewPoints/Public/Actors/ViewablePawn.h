// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Viewable.h"
#include "GameFramework/Pawn.h"
#include "ViewablePawn.generated.h"

class UInputAction;
class UViewPointComponent;

UCLASS()
class  VIEWPOINTS_API AViewablePawn : public APawn , public IViewable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AViewablePawn();
	virtual void ChangeViewPoint() override;
	virtual void MakeActiveViewable() override;
	virtual void MakeInactive() override;
	virtual void ResetToMain() override;
	virtual bool IsLocalPlayer() override { return IsLocallyControlled(); }
	virtual UViewPointComponent* GetCurrentViewPoint() const override { return CurrentViewPoint; }
protected:
	void CycleViewable();
	void CycleViewPoint();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TArray<TObjectPtr<UViewPointComponent>> ViewPoints;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UViewPointComponent> MainViewPoint;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UViewPointComponent> CurrentViewPoint;
};


