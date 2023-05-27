// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_ReturnToBaseSpeed.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Character/GJMonsterCharacter.h"

UBTTask_ReturnToBaseSpeed::UBTTask_ReturnToBaseSpeed()
{
    NodeName = TEXT("Return To Base Speed");
}

EBTNodeResult::Type UBTTask_ReturnToBaseSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
            Character->SetSpeed(Character->GetBaseSpeed());
        }
        return EBTNodeResult::Succeeded;
  }

    
}