// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GJInventoryComponent.h"

#include "Definitions.h"

void UGJInventoryComponent::CollectItem(UPickupData* PickupData)
{
	CollectedItems.Add(PickupData->Name, PickupData);
	OnPickupCollected.Broadcast(PickupData);
}

TMap<FName, UPickupData*> UGJInventoryComponent::GetCollectedItems() const
{
	return CollectedItems;
}

UPickupData* UGJInventoryComponent::GetDataWithKey(FName Key) const
{
	if (CollectedItems.Contains(Key))
	{
		return CollectedItems[Key];
	}
	return nullptr;
}

void UGJInventoryComponent::RemoveItem(FName Name)
{
	CollectedItems.Remove(Name);
}
