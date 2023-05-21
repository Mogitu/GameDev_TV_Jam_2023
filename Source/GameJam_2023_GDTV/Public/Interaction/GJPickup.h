// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GJInteractionInterface.h"
#include "GameFramework/Actor.h"
#include "GJPickup.generated.h"

class UPickupData;

UCLASS()
class GAMEJAM_2023_GDTV_API AGJPickup : public AActor, public IGJInteractionInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	UPickupData* PickupData;

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
