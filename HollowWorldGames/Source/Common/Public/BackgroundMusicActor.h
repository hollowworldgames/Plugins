// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundMusicActor.generated.h"

USTRUCT(BlueprintType)
struct FMusicMood
{
	GENERATED_BODY()
	public :
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Music)
	TArray<TObjectPtr<USoundCue>> Music;
};

UCLASS()
class COMMON_API ABackgroundMusicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackgroundMusicActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void StartMusic(int Mood);
	void StopMusic() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Music)
	TArray<FMusicMood> Moods;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UAudioComponent> AudioComponent;
	static TObjectPtr<USoundCue> LastPlayed;
	static float Progress;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	bool ForceRestart = false;
};
