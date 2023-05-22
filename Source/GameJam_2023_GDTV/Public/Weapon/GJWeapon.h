// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GJWeapon.generated.h"

UCLASS()
class GAMEJAM_2023_GDTV_API AGJWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGJWeapon();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
