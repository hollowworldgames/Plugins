// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitalComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrbitalSet, UOrbital*, Orbital);

class UOrbital;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GALAXY_API UOrbitalComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOrbitalComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void SetOrbital(UOrbital* NewOrbital);
	UFUNCTION(BlueprintPure)
	UOrbital * GetOrbital() const { return Orbital; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category="Data")
	TObjectPtr<UOrbital> Orbital;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOrbitalSet OnOrbitalSet;
};
