// Fill out your copyright notice in the Description page of Project Settings.


#include "RarestCandy.h"
#include "Components/StaticMeshComponent.h"
#include "G1213AlexCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARarestCandy::ARarestCandy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Final Stuff
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	StaticMesh->SetCollisionProfileName(FName("OverlapAll"));

}

// Called when the game starts or when spawned
void ARarestCandy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARarestCandy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0.0f, 90.0f * DeltaTime, 0.0f));

}

void ARarestCandy::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Player = Cast<AG1213AlexCharacter>(OtherActor);
	if (Player != nullptr)
	{
		Player->ChangeLevel(1 + Player->CollectedCandy++);
		if (PickupSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());
		}
		Destroy();
	}
}

