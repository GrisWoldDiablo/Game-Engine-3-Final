// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "G1213AlexCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "G1213AlexProjectile.h"
#include "Materials/MaterialInstanceDynamic.h"



// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Final Stuff
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->InitSphereRadius(Distance);
	SphereComponent->SetCollisionProfileName(FName("OverlapAll"));

}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	MaterialInstance = StaticMesh->CreateDynamicMaterialInstance(0);
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Start)
	{
		if (StartTime + Period <= GetWorld()->TimeSeconds)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetActorTransform());
			StartTime = GetWorld()->TimeSeconds;
			Player->GetCharacterMovement()->AddImpulse(Player->GetActorUpVector() * 1000.0f);
			Player->GetCharacterMovement()->AddRadialImpulse(GetActorLocation(), MAX_FLT, -StrongForce, ERadialImpulseFalloff::RIF_Constant, false);
		}
	}

}

void ABlackHole::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Player = Cast<AG1213AlexCharacter>(OtherActor);
	if (Player != nullptr && !Start)
	{
		MaterialInstance->SetScalarParameterValue(FName("Lerp"), 1.0f);
		Start = true;
		StartTime = GetWorld()->TimeSeconds;
	}
}

void ABlackHole::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<AG1213AlexProjectile>(Other) != nullptr)
	{
		Destroy();
	}
}

void ABlackHole::OnConstruction(const FTransform& Transform)
{
	SphereComponent->SetSphereRadius(Distance);
}

