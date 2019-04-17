// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheGamePlayerController.generated.h"

UCLASS()
class ATheGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATheGamePlayerController();

protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Orient the player to look at the mouse cursor location  */
	void LookAtMouse();
};


