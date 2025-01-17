// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "XRGameMode.generated.h"

/**
 * 
 */
UCLASS()
class XRCOMMON_API AXRGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
protected :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Classes")
	TSubclassOf<APawn> PlayerXRPawn;
};
