// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/GJDimensionHandlerComponent.h"

#include "GameMode/GJGameMode.h"

// Sets default values for this component's properties
UGJDimensionHandlerComponent::UGJDimensionHandlerComponent()
{
	bInitiallyEnabled = true;
}

// Called when the game starts
void UGJDimensionHandlerComponent::BeginPlay()
{
	Super::BeginPlay();
	AGJGameMode*  Mode =  GetWorld()->GetAuthGameMode<AGJGameMode>();
	Mode->OnDimensionSwitch.AddDynamic(this, &UGJDimensionHandlerComponent::OnDimensionSwitch);
	GetOwner()->SetActorHiddenInGame(bInitiallyEnabled);
}

void UGJDimensionHandlerComponent::OnDimensionSwitch_Implementation(bool bGhostDimensionActive)
{
	GetOwner()->SetActorHiddenInGame(bGhostDimensionActive != bInitiallyEnabled);
}

