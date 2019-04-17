// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TheGamePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TheGameCharacter.h"
#include "Engine/World.h"

ATheGamePlayerController::ATheGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATheGamePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	// keep updating the player orientation to look at mouse every tick
	LookAtMouse();
	
	
}

void ATheGamePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
}

void ATheGamePlayerController::LookAtMouse()
{

	//Gets local reference to the controller's character and its rotation
	ACharacter *currentChar = GetCharacter();


	//determine mouse Location in world space
	FHitResult mouseHit = FHitResult();
	bool bMouseResult = GetHitResultUnderCursor(ECC_Visibility, true, mouseHit);


	//create FVector MouseHitLoc to store the impact point of the location in world below the mouse
	FVector_NetQuantize MouseHitLoc = FVector_NetQuantize();

	//If we hit something set the location and update the rotation
	MouseHitLoc = mouseHit.ImpactPoint;

	//Get Pawn Loc
	FVector pPawnLoc = currentChar->GetActorLocation();

	//Create new vector from player to the mouse loc
	FVector TargetVector = (MouseHitLoc - pPawnLoc);
	TargetVector.Normalize();

	FRotator targetRotation = FRotator(0.f, TargetVector.Rotation().Yaw, 0.f);

	//set character to look at mouse cursor
	currentChar->SetActorRotation(targetRotation);
}
