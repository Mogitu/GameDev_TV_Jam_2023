// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GJInventoryComponent.h"

#include "Definitions.h"

void UGJInventoryComponent::CollectItem(UPickupData* PickupData)
{
	CollectedItems.Add(PickupData);
	OnPickupCollected.Broadcast(PickupData);
}
