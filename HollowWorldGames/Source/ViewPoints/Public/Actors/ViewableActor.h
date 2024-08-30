// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Viewable.h"
#include "GameFramework/Actor.h"
#include "ViewableActor.generated.h"

class UViewPointComponent;
class IViewPoint;

UCLASS()
class  VIEWPOINTS_API AViewableActor : public AActor, public IViewable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AViewableActor();
	virtual void ChangeViewPoint() override;
	virtual void MakeActiveViewable() override;
	virtual void MakeInactive() override;
	virtual void ResetToMain() override;
	virtual bool IsLocalPlayer() override { return false; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, Category=ViewPoints)
	TArray<TObjectPtr<UViewPointComponent>> ViewPoints;
	UPROPERTY(VisibleAnywhere, Transient, Category=ViewPoints)
	TObjectPtr<UViewPointComponent> CurrentViewPoint;
	UPROPERTY(VisibleAnywhere, Transient, Category=ViewPOints)
	TObjectPtr<UViewPointComponent> MainViewPoint;
};
