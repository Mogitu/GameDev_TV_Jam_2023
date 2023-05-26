// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/GJPickup.h"
#include "GJWeaponPartPickup.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJWeaponPartPickup : public AGJPickup
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnDimensionSwitch(bool bGhostDimensionActive);

protected:
	UPROPERTY(EditAnywhere, Category="Dimension")
	bool bInitiallyEnabled;
};
