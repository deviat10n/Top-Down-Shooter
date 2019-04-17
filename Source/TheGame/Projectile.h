// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class THEGAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector bulletLocation;
	FRotator bulletRotation;
	float bulletRotationRadians;
	float ninetyDegreeRadians;
	float sideA;
	float sideB;
	int bulletSpeed;

private:
	// A static mesh component. The visual representation of our actor
	class UStaticMeshComponent* BulletVisual;
	
};
