// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class G1213ALEX_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly) class AG1213AlexCharacter* Player;
	
};
