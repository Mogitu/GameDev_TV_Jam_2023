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
	Mode->OnDimensionSwitch.AddDynamic(this, &UGJDimensionHandlerComponent::OnDimensionSwitch);
}

void UGJDimensionHandlerComponent::SetDimensionSettings(EDimension NewDimension)
{
	switch (NewDimension)
	{
	case EDimension::GhostDimension:
		ApplyDimensionSettings(DimensionSettingsOverride != nullptr
			                       ? DimensionSettingsOverride->GhostDimensionSettings
			                       : GhostDimensionSettings);
		break;
	case EDimension::NormalDimension:
		ApplyDimensionSettings(DimensionSettingsOverride != nullptr
			                       ? DimensionSettingsOverride->NormalDimensionSettings
			                       : NormalDimensionSettings);
		break;
	}
}

void UGJDimensionHandlerComponent::ApplyDimensionSettings(FDimensionSettings Settings)
{
	GetOwner()->SetActorHiddenInGame(Settings.bIsHidden);
	GetOwner()->SetActorEnableCollision(!Settings.bDisableCollision);
}

void UGJDimensionHandlerComponent::OnDimensionSwitch_Implementation(EDimension NewDimension)
{
	SetDimensionSettings(NewDimension);
}
