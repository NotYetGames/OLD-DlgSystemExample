// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "DlgExampleDialogueData.h"
#include "DlgDialogueParticipant.h"

#include "DlgExampleCharacter.generated.h"

UCLASS(Blueprintable)
class ADlgExampleCharacter : public ACharacter, public IDlgDialogueParticipant
{
	GENERATED_BODY()

public:
	ADlgExampleCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }


	/** Dialogue System interface */

	FName GetParticipantName_Implementation() const override { return DlgParticipantName; }
	FText GetParticipantDisplayName_Implementation(FName ActiveSpeaker) const override { return DlgParticipantDisplayName; }
	UTexture2D* GetParticipantIcon_Implementation(FName ActiveSpeaker) const override { return DlgParticipantIcon; }

	bool ModifyIntValue_Implementation(const FName& ValueName, bool bDelta, int32 Value) override;
	bool ModifyFloatValue_Implementation(const FName& ValueName, bool bDelta, float Value) override;
	bool ModifyBoolValue_Implementation(const FName& ValueName, bool bValue) override;
	bool ModifyNameValue_Implementation(const FName& ValueName, const FName& NameValue) override;

	float GetFloatValue_Implementation(const FName& ValueName) const override;
	int32 GetIntValue_Implementation(const FName& ValueName) const override;
	bool GetBoolValue_Implementation(const FName& ValueName) const override;
	FName GetNameValue_Implementation(const FName& ValueName) const override;

	bool OnDialogueEvent_Implementation(const FName& EventName) override { return false; }
	bool CheckCondition_Implementation(const FName& ConditionName) const override { return false; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FDlgExampleDialogueData DlgData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FName DlgParticipantName = FName("MyCharacterName");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FText DlgParticipantDisplayName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	UTexture2D* DlgParticipantIcon;
};

