// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAutoRunComponent.generated.h"


class USplineComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONS_API UCharacterAutoRunComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterAutoRunComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void SetAutoRunDestination(const FVector& Destination);
protected:
	void MoveToPoint();
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category=Components)
	TObjectPtr<USplineComponent> SplineComponent;
	UPROPERTY(EditDefaultsOnly, Category=Settings)
	double AutorunAcceptanceRadius = 10.0f;
	bool AutoRun = false;
	FVector CachedLocation;
};
