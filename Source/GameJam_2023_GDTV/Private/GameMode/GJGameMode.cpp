// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GJGameMode.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"

void AGJGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->OnWorldBeginPlay.AddUObject(this, &AGJGameMode::Init);
}

void AGJGameMode::Init()
{
	SetDimension(NormalDimension);
}


void AGJGameMode::OnActorKilled(AActor* Victim, AActor* Killer)
{
	LogOnScreen(GetWorld(), Victim->GetName() + " was killed by " + Killer->GetName());
}

void AGJGameMode::SetDimension(EDimension NewDimension)
{
	CurrentDimension = NewDimension;
	OnDimensionSwitch.Broadcast(CurrentDimension);
}

void AGJGameMode::ToggleDimension()
{
	if (CurrentDimension == NormalDimension)
	{
		SetDimension(GhostDimension);
	}
	else
	{
		SetDimension(NormalDimension);
	}
}

EDimension AGJGameMode::GetCurrentDimension() const
{
	return CurrentDimension;
}
