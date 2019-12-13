// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cubemon.generated.h"

UCLASS()
class G1213ALEX_API ACubemon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubemon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Final Stuff
public:
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* StaticMesh;
	class UStaticMeshComponent* StaticMeshTwo;
	UPROPERTY(VisibleAnywhere) class UWidgetComponent* WidgetComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) int Level = 1;

	void ChangeLevel(int Amount);

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void OnConstruction(const FTransform& Transform) override;

};
