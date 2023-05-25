// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GJ_MonsterAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AGJ_MonsterAI::AGJ_MonsterAI()
{
    PrimaryActorTick.bCanEverTick = true;

}

void AGJ_MonsterAI::BeginPlay()
{
    Super::BeginPlay();
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    

    
    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    }
    
}

void AGJ_MonsterAI::Tick(float DeltaSeconds)
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    Super::Tick(DeltaSeconds);
}

