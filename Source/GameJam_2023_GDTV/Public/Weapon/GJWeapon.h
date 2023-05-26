// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GJWeapon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmmoChanged, int32, NewAmmo);

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

	UPROPERTY(BlueprintAssignable)
	FOnAmmoChanged OnAmmoChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	TSubclassOf<UUserWidget> WeaponDisplayWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> WeaponDisplayWidgetInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	USoundBase* FireSound;

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
