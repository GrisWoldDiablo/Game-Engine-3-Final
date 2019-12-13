// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "G1213AlexGameMode.h"
#include "G1213AlexHUD.h"
#include "G1213AlexCharacter.h"
#include "UObject/ConstructorHelpers.h"

AG1213AlexGameMode::AG1213AlexGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AG1213AlexHUD::StaticClass();
}
