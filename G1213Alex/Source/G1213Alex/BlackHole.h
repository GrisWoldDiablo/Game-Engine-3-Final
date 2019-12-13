// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class G1213ALEX_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Final Stuff
public:
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere) class USphereComponent* SphereComponent;
	UPROPERTY(EditAnywhere, category = "Default") float Distance = 300.0f;
	UPROPERTY(EditAnywhere, category = "Default") float Period = 1.7f;
	UPROPERTY(EditAnywhere, category = "Default") class UParticleSystem* Particle;
	UPROPERTY(EditAnywhere, category = "Default") float StrongForce = 50000.0f;

	class AG1213AlexCharacter* Player;
	class UMaterialInstanceDynamic* MaterialInstance;
	bool Start = false;
	float StartTime;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	virtual void OnConstruction(const FTransform& Transform) override;

};
