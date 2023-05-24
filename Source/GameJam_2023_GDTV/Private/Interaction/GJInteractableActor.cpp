// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJInteractableActor.h"

// Sets default values
AGJInteractableActor::AGJInteractableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGJInteractableActor::BeginPlay()
{
	Super::BeginPlay();
}

FText AGJInteractableActor::GetInteractText_Implementation(APawn* InstigatorPawn)
{
	return !InteractionText.IsEmpty() ? InteractionText : FText::FromString("-E-");
}
