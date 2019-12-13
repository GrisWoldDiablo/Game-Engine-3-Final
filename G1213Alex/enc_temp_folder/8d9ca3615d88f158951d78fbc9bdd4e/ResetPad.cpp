// Fill out your copyright notice in the Description page of Project Settings.


#include "ResetPad.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "G1213AlexCharacter.h"

// Sets default values
AResetPad::AResetPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Final Stuff
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetBoxExtent(FVector(50.0f, 50.0f, 60.0f));
}

// Called when the game starts or when spawned
void AResetPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResetPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimerStarted)
	{
		TimePassed = 1.0f * DeltaTime;
		if (FVector::Distance(GetActorLocation(),Player->GetTargetLocation()) > Distance)
		{
			TimerStarted = false;
			return;
		}
		if (TimePassed >= 1.0f)
		{
			Player->ChangeLevel(LevelToChange);
		}
		if (Player->Level == 10)
		{
			TimerStarted = false;
		}

	}

}

void AResetPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (!TimerStarted)
	{
		Player = Cast<AG1213AlexCharacter>(OtherActor);

		if (Player != nullptr)
		{
			auto currentLevel = Player->Level;
			TimerStarted = true;
			StartTime = GetWorld()->TimeSeconds;
			if (currentLevel > 10)
			{
				LevelToChange = -Speed;
			}
			else
			{
				LevelToChange = Speed;
			}

		}
	}
}

