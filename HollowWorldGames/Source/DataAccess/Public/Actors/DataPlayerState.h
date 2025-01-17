// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DataPlayerState.generated.h"

class UDataAccessComponent;

UCLASS()
class DATAACCESS_API ADataPlayerState : public APlayerState
{
	GENERATED_BODY()
public :
	UFUNCTION()
	void Multicast_PostLoad();
	virtual void Load(uint64 ActorId);
	UDataAccessComponent * GetDataAccessComponent() const { return DataAccessComponent; }
	void InitializeDataComponent();
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> SingleDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ServerDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ClientDataClass;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataAccessComponent> DataAccessComponent;
};
