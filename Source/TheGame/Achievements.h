// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Achievements.generated.h"

UCLASS()
class THEGAME_API AAchievements : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAchievements();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		int32 killCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		int32 waveCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		int32 scoreCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		int32 bulletCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		int32 timeCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool killCount1Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool killCount2Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool killCount3Unlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool waveCount1Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool waveCount2Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool waveCount3Unlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool scoreCount1Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool scoreCount2Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool scoreCount3Unlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool bulletCount1Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool bulletCount2Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool bulletCount3Unlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool timeCount1Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool timeCount2Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool timeCount3Unlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Achievements)
		bool allAchievementsUnlocked;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
