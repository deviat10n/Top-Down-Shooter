// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TheGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ATheGameCharacter::ATheGameCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	forwardPressed = false;
	backwardPressed = false;
	leftPressed = false;
	rightPressed = false;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATheGameCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UWorld* World = GetWorld())
			{
				FHitResult HitResult;
				FCollisionQueryParams Params(NAME_None, FCollisionQueryParams::GetUnknownStatId());
				FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
				FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
				Params.AddIgnoredActor(this);
				World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
				FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
				CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
			}
		}
		else if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}

	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	if (forwardPressed == true) {
		playerLocation.X = playerLocation.X + 5;
		this->SetActorLocation(playerLocation);
	}
	if (backwardPressed == true) {
		playerLocation.X = playerLocation.X - 5;
		this->SetActorLocation(playerLocation);
	}
	if (leftPressed == true) {
		playerLocation.Y = playerLocation.Y - 5;
		this->SetActorLocation(playerLocation);
	}
	if (rightPressed == true) {
		playerLocation.Y = playerLocation.Y + 5;
		this->SetActorLocation(playerLocation);
	}
}

void ATheGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind movement events
	FInputActionBinding& ForwardBindingPressed = InputComponent->BindAction("MoveForwardPressed", IE_Pressed, this, &ATheGameCharacter::MoveForwardPressed);
	FInputActionBinding& BackwardBindingPressed = InputComponent->BindAction("MoveBackwardPressed", IE_Pressed, this, &ATheGameCharacter::MoveBackwardPressed);
	FInputActionBinding& LeftBindingPressed = InputComponent->BindAction("MoveLeftPressed", IE_Pressed, this, &ATheGameCharacter::MoveLeftPressed);
	FInputActionBinding& RightBindingPressed = InputComponent->BindAction("MoveRightPressed", IE_Pressed, this, &ATheGameCharacter::MoveRightPressed);

	FInputActionBinding& ForwardBindingReleased = InputComponent->BindAction("MoveForwardReleased", IE_Released, this, &ATheGameCharacter::MoveForwardReleased);
	FInputActionBinding& BackwardBindingReleased = InputComponent->BindAction("MoveBackwardReleased", IE_Released, this, &ATheGameCharacter::MoveBackwardReleased);
	FInputActionBinding& LeftBindingReleased = InputComponent->BindAction("MoveLeftReleased", IE_Released, this, &ATheGameCharacter::MoveLeftReleased);
	FInputActionBinding& RightBindingReleased = InputComponent->BindAction("MoveRightReleased", IE_Released, this, &ATheGameCharacter::MoveRightReleased);
}

void ATheGameCharacter::MoveForwardPressed()
{
	forwardPressed = true;
}

void ATheGameCharacter::MoveForwardReleased()
{
	forwardPressed = false;
}

void ATheGameCharacter::MoveRightPressed()
{
	rightPressed = true;
}

void ATheGameCharacter::MoveRightReleased()
{
	rightPressed = false;
}

void ATheGameCharacter::MoveBackwardPressed()
{
	backwardPressed = true;
}

void ATheGameCharacter::MoveBackwardReleased()
{
	backwardPressed = false;
}

void ATheGameCharacter::MoveLeftPressed()
{
	leftPressed = true;
}

void ATheGameCharacter::MoveLeftReleased()
{
	leftPressed = false;
}