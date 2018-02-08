// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DlgExampleGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "DlgExamplePlayerController.h"
#include "DlgExampleCharacter.h"
#include "DlgSystemModule.h"

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
	if (FModuleManager::Get().IsModuleLoaded(DIALOGUE_SYSTEM_PLUGIN_NAME))
	{
		FModuleManager::LoadModuleChecked<FDlgSystemModule>(DIALOGUE_SYSTEM_PLUGIN_NAME).SetReferenceActor(this);
	}

	// register own commands probably
}