// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DlgExampleGameMode.generated.h"

UCLASS(minimalapi)
class ADlgExampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADlgExampleGameMode();

	void StartPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};



