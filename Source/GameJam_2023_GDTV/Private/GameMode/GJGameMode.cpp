// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GJGameMode.h"

#include "Interaction/GJPickup.h"
#include "Kismet/GameplayStatics.h"

bool AGJGameMode::AllWeaponPartsCollected()
{
	TArray<AActor*> WeaponParts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGJPickup::StaticClass(), WeaponParts);
	return WeaponParts.Num() == 0;
}

void AGJGameMode::OnActorKilled(AActor* Victim, AActor* Killer)
{
}
