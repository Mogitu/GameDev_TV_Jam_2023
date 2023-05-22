// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GJInteractionInterface.h"
#include "GameFramework/Actor.h"
#include "GJPickup.generated.h"

class UPickupData;
class USphereComponent;

UCLASS()
class GAMEJAM_2023_GDTV_API AGJPickup : public AActor, public IGJInteractionInterface
{
	GENERATED_BODY()

public:
	AGJPickup();

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	UPickupData* PickupData;

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	UPROPERTY(VisibleAnywhere, Category="Pickup")
	TObjectPtr<USphereComponent> CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category="Pickup")
	TObjectPtr<UStaticMeshComponent> PickupMesh;
};
