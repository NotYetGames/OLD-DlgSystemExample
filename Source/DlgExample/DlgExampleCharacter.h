// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "DlgExampleDialogueData.h"
#include "DlgDialogueParticipant.h"

#include "DlgExampleCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UDecalComponent;

class UDlgContext;

UCLASS(Blueprintable)
class ADlgExampleCharacter : public ACharacter, public IDlgDialogueParticipant
{
	GENERATED_BODY()

public:
	ADlgExampleCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE UDecalComponent* GetCursorToWorld() { return CursorToWorld; }


	/** Dialogue System interface / C++ Implementation */
	FName GetParticipantName_Implementation() const override { return DlgParticipantName; }
	ETextGender GetParticipantGender_Implementation() const override { return ETextGender::Neuter; }
	FText GetParticipantDisplayName_Implementation(FName ActiveSpeaker) const override { return DlgParticipantDisplayName; }
	UTexture2D* GetParticipantIcon_Implementation(FName ActiveSpeaker, FName ActiveSpeakerState) const override { return DlgParticipantIcon; }

	bool ModifyIntValue_Implementation(FName ValueName, bool bDelta, int32 Value) override;
	bool ModifyFloatValue_Implementation(FName ValueName, bool bDelta, float Value) override;
	bool ModifyBoolValue_Implementation(FName ValueName, bool bValue) override;
	bool ModifyNameValue_Implementation(FName ValueName, FName NameValue) override;

	float GetFloatValue_Implementation(FName ValueName) const override;
	int32 GetIntValue_Implementation(FName ValueName) const override;
	bool GetBoolValue_Implementation(FName ValueName) const override;
	FName GetNameValue_Implementation(FName ValueName) const override;

	bool OnDialogueEvent_Implementation(UDlgContext* Context, FName EventName) override { return false; }
	bool CheckCondition_Implementation(const UDlgContext* Context, FName ConditionName) const override { return false; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FDlgExampleDialogueData DlgData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FName DlgParticipantName = FName("MyCharacterName");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	FText DlgParticipantDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
	UTexture2D* DlgParticipantIcon;
};
