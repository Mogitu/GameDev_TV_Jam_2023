// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_MonsterSpeed.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "Character/GJMonsterCharacter.h"

UBTService_MonsterSpeed::UBTService_MonsterSpeed()
{
    NodeName = "Update Monster Speed";
}

void UBTService_MonsterSpeed::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    
    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }
    else
    {
        AGJMonsterCharacter* Character = Cast<AGJMonsterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
        if (Character == nullptr)
        {
            return;
        }
        else
        {
            Character->SetSpeed(Character->GetSpeed() + 30.0f);
        }
    }
}
