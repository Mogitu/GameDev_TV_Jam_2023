// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJWeaponPartPickup.h"

#include "GameMode/GJGameMode.h"

void AGJWeaponPartPickup::BeginPlay()
{
	Super::BeginPlay();
	AGJGameMode*  Mode =  GetWorld()->GetAuthGameMode<AGJGameMode>();
	Mode->OnDimensionSwitch.AddDynamic(this, &AGJWeaponPartPickup::OnDimensionSwitch);

	SetActorHiddenInGame(bInitiallyEnabled);
}

void AGJWeaponPartPickup::OnDimensionSwitch(bool bGhostDimensionActive)
{
	SetActorHiddenInGame(bGhostDimensionActive != bInitiallyEnabled);
}
