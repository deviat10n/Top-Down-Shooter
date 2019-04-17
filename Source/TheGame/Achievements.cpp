// Fill out your copyright notice in the Description page of Project Settings.

#include "Achievements.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine.h"
#include "TimerManager.h"
#include "iostream"
#include "cstdio"
#include "ctime"
#include "Components/InputComponent.h"

// Sets default values
AAchievements::AAchievements()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAchievements::BeginPlay()
{
	Super::BeginPlay();
	
	killCount1Unlocked = false;
	killCount2Unlocked = false;
	killCount3Unlocked = false;

	waveCount1Unlocked = false;
	waveCount2Unlocked = false;
	waveCount3Unlocked = false;

	scoreCount1Unlocked = false;
	scoreCount2Unlocked = false;
	scoreCount3Unlocked = false;

	bulletCount1Unlocked = false;
	bulletCount2Unlocked = false;
	bulletCount3Unlocked = false;

	timeCount1Unlocked = false;
	timeCount2Unlocked = false;
	timeCount3Unlocked = false;

	allAchievementsUnlocked = false;
}

// Called every frame
void AAchievements::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (killCount > 50) killCount3Unlocked = true;
	else if (killCount > 25) killCount2Unlocked = true;
	else if (killCount > 10) killCount1Unlocked = true;

	if (waveCount > 10) waveCount3Unlocked = true;
	else if (killCount > 5) waveCount2Unlocked = true;
	else if (killCount > 3) waveCount1Unlocked = true;

	if (scoreCount > 5000) scoreCount3Unlocked = true;
	else if (scoreCount > 2000) scoreCount2Unlocked = true;
	else if (scoreCount > 500) scoreCount1Unlocked = true;

	if (bulletCount > 500) bulletCount3Unlocked = true;
	else if (bulletCount > 250) bulletCount2Unlocked = true;
	else if (bulletCount > 100) bulletCount1Unlocked = true;

	if (timeCount > 300) timeCount3Unlocked = true;
	else if (timeCount > 150) timeCount2Unlocked = true;
	else if (timeCount > 60) timeCount1Unlocked = true;

	if (killCount1Unlocked == true && killCount2Unlocked == true && killCount3Unlocked == true && waveCount1Unlocked == true && waveCount2Unlocked == true && waveCount3Unlocked == true && scoreCount1Unlocked == true && scoreCount2Unlocked == true && scoreCount3Unlocked == true && bulletCount1Unlocked == true && bulletCount2Unlocked == true && bulletCount3Unlocked == true && timeCount1Unlocked == true && timeCount2Unlocked == true && timeCount3Unlocked == true) allAchievementsUnlocked = true;
}

