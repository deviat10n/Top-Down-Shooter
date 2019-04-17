// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TheGameGameMode.h"
#include "TheGamePlayerController.h"
#include "TheGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheGameGameMode::ATheGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATheGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}