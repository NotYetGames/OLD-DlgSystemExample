// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DlgExampleGameMode.h"
#include "DlgExamplePlayerController.h"
#include "DlgExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADlgExampleGameMode::ADlgExampleGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADlgExamplePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}