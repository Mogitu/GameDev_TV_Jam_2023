// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJPickup.h"
#include "Character/GJInventoryComponent.h"
#include "Components/SphereComponent.h"

AGJPickup::AGJPickup()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	SetRootComponent(CollisionSphere);

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(GetRootComponent());
}

void AGJPickup::Interact_Implementation(APawn* InstigatorPawn)
{
	if (auto Inventory = InstigatorPawn->FindComponentByClass<UGJInventoryComponent>())
	{
		Inventory->CollectItem(PickupData);
	}
	Destroy();
}
