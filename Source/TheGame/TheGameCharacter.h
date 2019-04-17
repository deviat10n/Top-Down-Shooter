// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TheGameCharacter.generated.h"

UCLASS(Blueprintable)
class ATheGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATheGameCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

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

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface


	void MoveForwardPressed();
	void MoveBackwardPressed();
	void MoveLeftPressed();
	void MoveRightPressed();
	void MoveForwardReleased();
	void MoveBackwardReleased();
	void MoveLeftReleased();
	void MoveRightReleased();

	bool forwardPressed;
	bool backwardPressed;
	bool leftPressed;
	bool rightPressed;
};

