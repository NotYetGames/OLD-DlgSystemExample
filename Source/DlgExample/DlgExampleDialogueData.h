// Copyright 2017-2018 Csaba Molnar, Daniel Butum

#pragma once

#include "CoreMinimal.h"
#include "DlgExampleDialogueData.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct FDlgExampleDialogueData
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FName, int32> Integers;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FName, int32> Floats;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TMap<FName, FName> Names;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TSet<FName> TrueBools;
};
