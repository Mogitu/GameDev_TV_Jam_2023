// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GJ_MonsterAI.h"

#include "Kismet/GameplayStatics.h"

void AGJ_MonsterAI::BeginPlay()
{
    Super::BeginPlay();
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    
    SetFocus(PlayerPawn);
}