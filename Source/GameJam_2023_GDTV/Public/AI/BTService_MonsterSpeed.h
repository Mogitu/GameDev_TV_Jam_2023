// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_MonsterSpeed.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UBTService_MonsterSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()

	public:
	UBTService_MonsterSpeed();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
