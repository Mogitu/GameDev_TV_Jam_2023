// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJPickup.h"
#include "Character/GJInventoryComponent.h"

void AGJPickup::Interact_Implementation(APawn* InstigatorPawn)
{
	if (auto Inventory = InstigatorPawn->FindComponentByClass<UGJInventoryComponent>())
	{
		Inventory->CollectItem(PickupData);
	}
	Destroy();
}
