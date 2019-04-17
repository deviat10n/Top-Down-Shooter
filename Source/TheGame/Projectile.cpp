// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine.h"
#include "TimerManager.h"
#include "iostream"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach a static mesh component.
	BulletVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	// Set the mesh to the root component.
	RootComponent = BulletVisual;

	// Set the mesh for the static mesh component.
	ConstructorHelpers::FObjectFinder<UStaticMesh> BulletAsset(TEXT("StaticMesh'/Game/Bullet.Bullet'"));

	// If the mesh was found set it and set properties.
	if (BulletAsset.Succeeded())
	{
		BulletVisual->SetStaticMesh(BulletAsset.Object);
	}
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bulletLocation = GetActorLocation();
	bulletRotation = GetActorRotation();
	bulletSpeed = 10;

	/*if (bulletRotation.Yaw >= 0 && bulletRotation.Yaw <= 90) {
		bulletRotationRadians = (bulletRotation.Yaw * 3.14159) / 180;
		ninetyDegreeRadians = (90 * 3.14159) / 180;

		sideA = ((FMath::Sin(bulletRotationRadians)) / FMath::Sin(ninetyDegreeRadians)) * 10;
		sideB = ((FMath::Sin((90 - bulletRotationRadians))) / FMath::Sin(ninetyDegreeRadians)) * 10;

		bulletLocation.X = bulletLocation.X + sideB;
		bulletLocation.Y = bulletLocation.Y + sideA;
	}
	else if (bulletRotation.Yaw > 90 && bulletRotation.Yaw <= 180) {
		bulletRotation.Yaw = 180 - bulletRotation.Yaw;
		bulletRotationRadians = (bulletRotation.Yaw * 3.14159) / 180;
		ninetyDegreeRadians = (90 * 3.14159) / 180;

		sideA = ((FMath::Sin(bulletRotationRadians)) / FMath::Sin(ninetyDegreeRadians)) * 10;
		sideB = ((FMath::Sin((90 - bulletRotationRadians))) / FMath::Sin(ninetyDegreeRadians)) * 10;

		bulletLocation.X = bulletLocation.X - sideB;
		bulletLocation.Y = bulletLocation.Y + sideA;
	}

	this->SetActorLocation(bulletLocation); 
	

	GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %f - %f - %f"), bulletRotation.Pitch, bulletRotation.Yaw, bulletRotation.Roll));
	*/
}

