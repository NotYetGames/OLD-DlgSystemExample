// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DlgExampleGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "DlgExamplePlayerController.h"
#include "DlgExampleCharacter.h"
#include "IDlgSystemModule.h"

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

void ADlgExampleGameMode::StartPlay()
{
	Super::StartPlay();
	PrimaryActorTick.bCanEverTick = true;

	// Register plugin console commands
	if (IDlgSystemModule::IsAvailable())
	{
		IDlgSystemModule::Get().RegisterConsoleCommands(this);
	}

	// register own commands probably
}

void ADlgExampleGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Unregister all the console commands
	if (IDlgSystemModule::IsAvailable())
	{
		IDlgSystemModule::Get().UnregisterConsoleCommands();
	}
}