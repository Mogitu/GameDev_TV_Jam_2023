// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GJGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDimensionSwitch, bool, bGhostDimensionActive);

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AllWeaponPartsCollected();

	void OnActorKilled(AActor* Victim, AActor* Killer);

	UFUNCTION(BlueprintCallable)
	void SwapDimension();

	UPROPERTY(BlueprintAssignable)
	FOnDimensionSwitch OnDimensionSwitch;

	UFUNCTION(BlueprintCallable)
	bool GetGhostDimensionActive() const;

protected:
	bool bGhostDimensionActive;
};
