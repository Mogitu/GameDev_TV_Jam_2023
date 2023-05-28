// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GJGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Character/GJMonsterCharacter.h"
#include "Character/GJPlayerCharacter.h"
#include "Components/AudioComponent.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"

AGJGameMode::AGJGameMode()
{
	NormalAudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("NormalAudioComp"));
	GhostAudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("GhostAudioComp"));
	MusicFadeDuration = 3;
}

void AGJGameMode::BeginPlay()
{
	Super::BeginPlay();
	GhostAudioComp->FadeOut(0, 0);
	GetWorld()->OnWorldBeginPlay.AddUObject(this, &AGJGameMode::Init);
}

void AGJGameMode::OnGameEnd()
{
	if (WidgetClassToSpawn)
	{
		auto Widget = CreateWidget(GetWorld(), WidgetClassToSpawn);
		Widget->AddToViewport();
	}
}

void AGJGameMode::Init()
{
	SetDimension(NormalDimension);
}

void AGJGameMode::OnActorKilled(AActor* Victim, AActor* Killer)
{
	LogOnScreen(GetWorld(), Victim->GetName() + " was killed by " + Killer->GetName());

	if (auto PlayerCharacter = Cast<AGJPlayerCharacter>(Victim))
	{
		if (GameOverWidgetClass)
		{
			WidgetClassToSpawn = GameOverWidgetClass;
		}
	}
	else if (auto MonsterCharacter = Cast<AGJMonsterCharacter>(Victim))
	{
		if (GameWinWidgetClass)
		{
			WidgetClassToSpawn = GameWinWidgetClass;
		}
	}

	GetWorldTimerManager().SetTimer(GameEndTimerHandle, this, &AGJGameMode::OnGameEnd, 5, false);
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
		NormalAudioComp->FadeOut(MusicFadeDuration, 0);
		GhostAudioComp->FadeIn(MusicFadeDuration, 1);
	}
	else
	{
		SetDimension(NormalDimension);
		NormalAudioComp->FadeIn(MusicFadeDuration, 1);
		GhostAudioComp->FadeOut(MusicFadeDuration, 0);
	}
}

EDimension AGJGameMode::GetCurrentDimension() const
{
	return CurrentDimension;
}
