// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "GJ_MonsterAI.generated.h"


/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJ_MonsterAI : public AAIController
{
	GENERATED_BODY()

public:

	AGJ_MonsterAI();
	virtual void Tick(float DeltaSeconds) override;

	UINT SetSpeedTime;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
	
};
