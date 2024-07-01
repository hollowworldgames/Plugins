// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABullet::ABullet() : AActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<UBoxComponent>("Root");
	Root->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetRootComponent(Root);
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>("Movement");
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	Root->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
	Movement->OnProjectileStop.AddDynamic(this, &ABullet::OnStop);
}

void ABullet::OnStop(const FHitResult& ImpactResult)
{
	if(GetWorld() && ImpactResult.GetActor() == nullptr)
	{
		GetWorld()->DestroyActor(this);
	}
}

void ABullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//hit do damage
	if(GetInstigator())
	{
		UGameplayStatics::ApplyDamage(OtherActor, MaxDamage, GetInstigator()->GetController(), GetInstigator() , DamageClass);
		if(GetWorld())
		{
			GetWorld()->DestroyActor(this);
		}
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Launch(const FVector& Location, const FVector& Velocity, const FRotator& Direction, APawn * Firer)
{
	Root->IgnoreActorWhenMoving(Firer, true);
	SetActorLocation(Location);
	SetActorRotation(Direction);
	Movement->Velocity = Velocity;
}

