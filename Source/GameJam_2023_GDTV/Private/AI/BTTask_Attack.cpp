// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Character/GJMonsterCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
    NodeName = TEXT("Attack");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
            Character->Attack();
        }
        return EBTNodeResult::Succeeded;
  }

    
}