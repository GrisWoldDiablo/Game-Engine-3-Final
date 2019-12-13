// Fill out your copyright notice in the Description page of Project Settings.


#include "UnluckyTrap.h"
#include "Components/StaticMeshComponent.h"
#include "G1213AlexCharacter.h"

// Sets default values
AUnluckyTrap::AUnluckyTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Final stuff
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetSimulatePhysics(true);
	RootComponent = StaticMesh;
	
}

// Called when the game starts or when spawned
void AUnluckyTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnluckyTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnluckyTrap::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto Player = Cast<AG1213AlexCharacter>(Other);

	if (Player != nullptr)
	{
		if (Player->Level % Unlucky == 0)
		{
			Player->ChangeLevel(-2);
		}
		else
		{
			Player->ChangeLevel(-1);
		}
		Destroy();
	}
}

