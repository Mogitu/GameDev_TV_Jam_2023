// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/GJDimensionHandlerComponent.h"
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
	if (DimensionSettingsOverride)
	{
		GhostDimensionSettings = DimensionSettingsOverride->GhostDimensionSettings;
		NormalDimensionSettings = DimensionSettingsOverride->NormalDimensionSettings;
	}
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

FDimensionSettings UGJDimensionHandlerComponent::GetCurrentDimensionSettings() const
{
	return CurrentDimensionSettings;
}

void UGJDimensionHandlerComponent::ApplyDimensionSettings(FDimensionSettings Settings)
{
	GetOwner()->SetActorHiddenInGame(Settings.bIsHidden);
	GetOwner()->SetActorEnableCollision(!Settings.bDisableCollision);
	CurrentDimensionSettings = Settings;
}

void UGJDimensionHandlerComponent::ChangeSettingsForDimension(EDimension Dimension, FDimensionSettings Settings)
{
	switch (Dimension)
	{
	case EDimension::NormalDimension:
		NormalDimensionSettings = Settings;
		break;
	case EDimension::GhostDimension:
		GhostDimensionSettings = Settings;
		break;
	}
}

void UGJDimensionHandlerComponent::OnDimensionSwitch_Implementation(EDimension NewDimension)
{
	SetDimensionSettings(NewDimension);
}
