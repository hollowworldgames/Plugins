// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MineableResourceComponent.h"
#include "Components/ActorComponent.h"
#include "MineableFieldResourceComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECONOMY_API UMineableFieldResourceComponent : public UMineableResourceComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMineableFieldResourceComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
