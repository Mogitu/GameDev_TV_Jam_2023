// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_IncreaseSpeed.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UBTTask_IncreaseSpeed : public UBTTaskNode
{
	GENERATED_BODY()
	
	public:
	UBTTask_IncreaseSpeed();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
