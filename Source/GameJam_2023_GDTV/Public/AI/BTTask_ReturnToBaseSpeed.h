// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ReturnToBaseSpeed.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UBTTask_ReturnToBaseSpeed : public UBTTaskNode
{
	GENERATED_BODY()

	public:	
	UBTTask_ReturnToBaseSpeed();

	protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
