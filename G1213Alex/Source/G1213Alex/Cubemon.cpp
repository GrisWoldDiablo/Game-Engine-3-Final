// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "CubemonLevel.h"
#include "G1213AlexProjectile.h"
#include "kismet/GameplayStatics.h"

// Sets default values
ACubemon::ACubemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	StaticMeshTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Two"));
	StaticMeshTwo->SetupAttachment(RootComponent);
	StaticMeshTwo->SetRelativeLocation(FVector(0.0f, 0.0f, 75.0f));
	StaticMeshTwo->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget Component"));
	//WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	WidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();
	auto CubemonHP = Cast<UCubemonLevel>(WidgetComponent->GetUserWidgetObject());
	if (CubemonHP != nullptr)
	{
		CubemonHP->Cubemon = this;
	}
	
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerCamera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	if (PlayerCamera != nullptr)
	{
		auto PlayerCameraRotation = PlayerCamera->GetCameraRotation();
		WidgetComponent->SetWorldRotation(PlayerCameraRotation);
		WidgetComponent->AddLocalRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}

void ACubemon::ChangeLevel(int Amount)
{
	Level += Amount;
	if (Level < 1)
	{
		Level = 1;
	}
	else if (Level > 99)
	{
		Level = 99;
	}
}

void ACubemon::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<AG1213AlexProjectile>(Other) != nullptr)
	{
		ChangeLevel(-1);
	}
}

void ACubemon::OnConstruction(const FTransform& Transform)
{
	StaticMeshTwo->SetStaticMesh(StaticMesh->GetStaticMesh());
}

