// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/SystemId.h"
#include "MineableResourceComponent.generated.h"

const FName MINEABLE_TAG("Mineable");

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECONOMY_API UMineableResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMineableResourceComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void SetMineableResources(const FSystemId& SystemId);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Resources)
	TObjectPtr<UDataTable> ResourceTable;
};
