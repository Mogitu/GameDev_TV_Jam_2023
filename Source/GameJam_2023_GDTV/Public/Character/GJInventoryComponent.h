// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GJInventoryComponent.generated.h"

class AGJPickup;
class UPickupData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickupCollected, UPickupData*, PickupData);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEJAM_2023_GDTV_API UGJInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void CollectItem(UPickupData* PickupData);

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	TArray<TSubclassOf<AActor>> RequiredGunParts;

	UPROPERTY(BlueprintAssignable)
	FOnPickupCollected OnPickupCollected;

	UFUNCTION(BlueprintCallable)
	TArray<UPickupData*> GetCollectedItems() const;

	UFUNCTION(BlueprintCallable)
	UPickupData* PopItem();

private:
	UPROPERTY()
	TArray<UPickupData*> CollectedItems;
};
