// Fill out your copyright notice in the Description page of Project Settings.


#include "Missile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMissile::AMissile() : AActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USphereComponent>("Root");
	Root->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Root->SetSphereRadius(1000);
	SetRootComponent(Root);
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Movement");
	MovementComponent->bIsHomingProjectile = true;
}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();
	Root->OnComponentBeginOverlap.AddDynamic(this, &AMissile::OnBeginOverlap);
	MovementComponent->OnProjectileStop.AddDynamic(this, &AMissile::OnStop);
}

void AMissile::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//KBoom!!!!!!!!
	if(GetInstigator())
	{
		UGameplayStatics::ApplyDamage(OtherActor, MaxDamage, GetInstigator()->GetController(), GetInstigator() , DamageClass);

		OnBoom(GetActorLocation(), GetActorRotation());

		if(ensure(GetWorld()))
		{
			GetWorld()->DestroyActor(this);
		}
	}
}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(Power > 0)
	{
		MovementComponent->AddForce(GetActorForwardVector() * (MaxThrustKN * 10000.0));
		Power -= PowerBurn * DeltaTime;
	}

	if(ArmTime > 0)
	{
		ArmTime -= DeltaTime;
		if(ArmTime < 0)
		{
			Root->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
	}
}

void AMissile::FireAt(FVector location, FVector momentum, AActor* target)
{
	Target = target;
	MovementComponent->HomingTargetComponent = target->GetRootComponent();
}

void AMissile::OnStop(const FHitResult& result)
{
	if(ensure(GetWorld()) && result.GetActor() == nullptr)
	{
		GetWorld()->DestroyActor(this);
	}
}

