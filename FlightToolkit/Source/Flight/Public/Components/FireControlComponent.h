// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FireControlComponent.generated.h"


class USensorDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLIGHT_API UFireControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFireControlComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sensors)
	TArray<TSubclassOf<USensorDefinition>> SensorClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Sensors)
	TArray<TObjectPtr<USensorDefinition>> Sensors;
};
