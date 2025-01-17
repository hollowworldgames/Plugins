// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ViewablePawn.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/DataComponentInterface.h"
#include "DataPawn.generated.h"

class UDataAccessComponent;

UCLASS()
class DATAACCESS_API ADataPawn : public AViewablePawn, public IDataComponentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADataPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Load(int64 NewActorId) override;
	void Save() const;
	UFUNCTION()
	virtual void OnLoaded();
	virtual void OnPrepareSave() const;
	virtual UDataAccessComponent * GetDataAccessComponent() const override { return DataAccessComponent; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> SingleDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ServerDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ClientDataClass;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataAccessComponent> DataAccessComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int64 ActorId;
private :
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PostLoad();
};


