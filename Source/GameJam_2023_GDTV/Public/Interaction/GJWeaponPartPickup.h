// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/GJPickup.h"
#include "GJWeaponPartPickup.generated.h"

class UGJDimensionHandlerComponent;
/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJWeaponPartPickup : public AGJPickup
{
	GENERATED_BODY()

public:
	AGJWeaponPartPickup();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dimension")
	TObjectPtr<UGJDimensionHandlerComponent> DimensionHandlerComponent;
};
