// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/Interface.h"
#include "Targetable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable, BlueprintType)
class UTargetable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DAMAGE_API ITargetable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual int64 GetId() { return Id; }
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual void SetId(int64 id) { Id = id; }
	virtual ETeamAttitude::Type GetTeamAttitude(AActor * Actor);
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual AActor * GetActor() = 0;
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual FVector GetLocation() = 0;
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual FRotator GetRotation() = 0;
	UFUNCTION(BlueprintCallable, Category="Targetable")
	virtual void NotifyTracking(TScriptInterface<ITargetable> tracker) = 0;
	virtual double GetSignature() = 0;
	virtual bool IsDestroyed() = 0;
protected :
	int64 Id = 0;
};
