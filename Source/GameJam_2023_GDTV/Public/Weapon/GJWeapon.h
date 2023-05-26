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

	UFUNCTION(BlueprintCallable)
	UStaticMeshComponent* GetWeaponMesh();

	UFUNCTION(BlueprintCallable)
	void Equip(AActor* ActorThatEquips, USceneComponent* Comp);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable)
	void AddAmmo(int32 Amount);

	UFUNCTION(BlueprintCallable)
	void DepleteAmmo(int32 Amount);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	float ShotDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	int32 MaxAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	float DamageAmount;

	UPROPERTY(BlueprintReadOnly, Category="Weapon")
	int32 CurrentAmmo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	APawn* OwningCharacter;
};
