// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"

// Sets default values
ACubemon::ACubemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

