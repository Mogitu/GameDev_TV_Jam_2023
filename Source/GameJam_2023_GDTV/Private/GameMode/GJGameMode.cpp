// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GJGameMode.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"

void AGJGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AGJGameMode::OnActorKilled(AActor* Victim, AActor* Killer)
{
	LogOnScreen(GetWorld(), Victim->GetName() + " was killed by " + Killer->GetName());
}

void AGJGameMode::SwapDimension(EDimension NewDimension)
{
	CurrentDimension = NewDimension;
	OnDimensionSwitch.Broadcast(CurrentDimension);
}

void AGJGameMode::ToggleDimension()
{
	if (CurrentDimension == NormalDimension)
	{
		SwapDimension(GhostDimension);
	}
	else
	{
		SwapDimension(NormalDimension);
	}
}

EDimension AGJGameMode::GetCurrentDimension() const
{
	return CurrentDimension;
}
