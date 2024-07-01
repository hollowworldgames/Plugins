// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "BackgroundMusicActor.h"
#include "UtilityStatics.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

TObjectPtr<USoundCue> ABackgroundMusicActor::LastPlayed;
float ABackgroundMusicActor::Progress = 0;

// Sets default values
ABackgroundMusicActor::ABackgroundMusicActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AudioComponent = CreateDefaultSubobject<UAudioComponent>("Root");
	SetRootComponent(AudioComponent);
}

// Called when the game starts or when spawned
void ABackgroundMusicActor::BeginPlay()
{
	Super::BeginPlay();
	if(ForceRestart)
	{
		LastPlayed = nullptr;
	}
	if(LastPlayed)
	{
		AudioComponent->Sound = LastPlayed;
		AudioComponent->Play(Progress);
	}
	else
	{
		StartMusic(0);
	}
}

// Called every frame
void ABackgroundMusicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(AudioComponent && !AudioComponent->IsPlaying())
	{
		StartMusic(0);
	}
	else
	{
		Progress += DeltaTime;
	}
}

void ABackgroundMusicActor::StartMusic(int Mood)
{
	Progress = 0;
	LastPlayed = UUtilityStatics::GetRandomItem(Moods[Mood].Music);
	AudioComponent->Sound = LastPlayed;
	AudioComponent->Play(0);
}

void ABackgroundMusicActor::StopMusic() const
{
	AudioComponent->Stop();
	LastPlayed = nullptr;
	Progress = 0;
}

