// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/GJDimensionHandlerComponent.h"

#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"
#include "GameMode/GJGameMode.h"

// Sets default values for this component's properties
UGJDimensionHandlerComponent::UGJDimensionHandlerComponent()
{
}

// Called when the game starts
void UGJDimensionHandlerComponent::BeginPlay()
{
	Super::BeginPlay();
	AGJGameMode* Mode = GetWorld()->GetAuthGameMode<AGJGameMode>();
	Mode->OnDimensionSwitch.AddDynamic(this, &UGJDimensionHandlerComponent::OnDimensionSwitch);
}

void UGJDimensionHandlerComponent::SetDimensionSettings(EDimension NewDimension)
{
	switch (NewDimension)
	{
	case EDimension::GhostDimension:
		ApplyDimensionSettings(GhostDimensionSettings);
		break;
	case EDimension::NormalDimension:
		ApplyDimensionSettings(NormalDimensionSettings);
		break;
	}
}

void UGJDimensionHandlerComponent::ApplyDimensionSettings(FDimensionSettings Settings)
{
	GetOwner()->SetActorHiddenInGame(Settings.bIsHidden);
}

void UGJDimensionHandlerComponent::OnDimensionSwitch_Implementation(EDimension NewDimension)
{
	SetDimensionSettings(NewDimension);
}
