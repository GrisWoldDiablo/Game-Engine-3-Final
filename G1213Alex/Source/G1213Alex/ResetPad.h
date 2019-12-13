// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResetPad.generated.h"

UCLASS()
class G1213ALEX_API AResetPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResetPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Final Stuff
public:
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere) class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere) float Distance = 200.0f;
	UPROPERTY(EditAnywhere) float Speed = 1;

	class AG1213AlexCharacter* Player;
	bool TimerStarted = false;
	float StartTime = 0.0f;
	int LevelToChange = 0;
	float TimePassed = 0.0f;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


};
