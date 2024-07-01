// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MissileLauncher.generated.h"


class ITargetable;
class AMissile;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAMAGE_API UMissileLauncher : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMissileLauncher();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void SetClass(TSubclassOf<AMissile> Class) { MissileClass = Class; }
	void SetQty(int NewQty) { Qty = NewQty; }
	virtual void LaunchAt(TScriptInterface<ITargetable> Target);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Missile)
	TSubclassOf<AMissile> MissileClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Missile)
	int Qty = 0;
};
