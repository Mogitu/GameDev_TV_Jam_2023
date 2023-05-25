// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation()
{
    NodeName = "Random Move";
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController)
    {
        return EBTNodeResult::Failed;
    }

    APawn* Pawn = AIController->GetPawn();
    if (!Pawn)
    {
        return EBTNodeResult::Failed;
    }

    FVector CurrentLocation = Pawn->GetActorLocation();
    UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(Pawn->GetWorld());
    if (!NavSystem)
    {
        return EBTNodeResult::Failed;
    }

    FNavLocation RandomLocation;
    float SearchRadius = 1000.0f; // Adjust this value to change the range of random movement
    if (NavSystem->GetRandomReachablePointInRadius(CurrentLocation, SearchRadius, RandomLocation))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), RandomLocation.Location);
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}