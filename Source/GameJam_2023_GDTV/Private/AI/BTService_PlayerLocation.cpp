// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "NavigationSystem.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
    NodeName = "Update Player Location";
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController == nullptr)
    {
        return;
    }

    APawn* AIPawn = AIController->GetPawn();
    if (!AIPawn)
    {
        return;
    }  

    FVector AICurrentLocation = AIPawn->GetActorLocation();
    UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(AIPawn->GetWorld());
    if (!NavSystem)
    {
        return;
    }

    FNavLocation RandomLocationNearPlayer;


    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
    {
        return;
    }

    FVector PlayerLocation = PlayerPawn->GetActorLocation();

    if (NavSystem->GetRandomReachablePointInRadius(PlayerLocation, 100.0f, RandomLocationNearPlayer))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), RandomLocationNearPlayer.Location);
        return;
    }

    
}

