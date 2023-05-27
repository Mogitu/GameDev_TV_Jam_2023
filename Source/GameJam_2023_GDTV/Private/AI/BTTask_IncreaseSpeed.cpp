// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_IncreaseSpeed.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Character/GJMonsterCharacter.h"

UBTTask_IncreaseSpeed::UBTTask_IncreaseSpeed()
{
    NodeName = TEXT("Increase Speed");
}

EBTNodeResult::Type UBTTask_IncreaseSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    } else {
        AGJMonsterCharacter* Character = Cast<AGJMonsterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
        if (Character == nullptr)
        {
            return EBTNodeResult::Failed;
        }
        else {
            Character->SetSpeed(Character->GetSpeed() + 30.0f);
        }
        return EBTNodeResult::Succeeded;
  }

    
}