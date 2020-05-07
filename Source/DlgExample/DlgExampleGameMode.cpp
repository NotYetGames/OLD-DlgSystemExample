// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DlgExampleGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "DlgExamplePlayerController.h"
#include "DlgExampleCharacter.h"
#include "DlgManager.h"

ADlgExampleGameMode::ADlgExampleGameMode()
{
	//
	// C++ version, can be overriden in BP
	//

	// use our custom PlayerController class
	PlayerControllerClass = ADlgExamplePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADlgExampleGameMode::StartPlay()
{
	//
	// C++ version, can be overriden in BP
	//

	// We must clear the Dialogue memory here because the FDlgMemory is a singleton and it remains in memory. Causes
	// problems in PIE and play in editor.
	UDlgManager::ClearDialogueHistory();

	Super::StartPlay();
	PrimaryActorTick.bCanEverTick = true;

	// Register plugin console commands
	// UDlgManager::SetPersistentWorldContextObject(this);
	// UDlgManager::RegisterDialogueConsoleCommands();

	// register own commands probably
}

void ADlgExampleGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//
	// C++ version, can be overriden in BP
	//

	// Unregister all the console commands
	// UDlgManager::UnregisterDialogueConsoleCommands();
}
