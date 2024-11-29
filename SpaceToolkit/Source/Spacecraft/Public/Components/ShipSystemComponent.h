// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Actors/Systems/SystemActor.h"
#include "Components/ChildActorComponent.h"
#include "ShipSystemComponent.generated.h"


class ASystemActor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACECRAFT_API UShipSystemComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UShipSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	ASystemActor * GetShipSystemActor() const { return ShipSystem; }
	FGameplayTag GetComponentTag() const { return (ensure(ShipSystem)) ? ShipSystem->GetComponentTag() : FGameplayTag(); }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "System")
	TObjectPtr<class ASystemActor> ShipSystem;
};
