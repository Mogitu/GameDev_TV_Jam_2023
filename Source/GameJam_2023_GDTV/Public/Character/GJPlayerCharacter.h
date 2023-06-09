// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GJCharacter.h"
#include "GJPlayerCharacter.generated.h"

class AGJWeapon;
class UGJUserWidget;
class UGJInteractionComponent;
class UGJInventoryComponent;
class UCameraComponent;

UCLASS()
class GAMEJAM_2023_GDTV_API AGJPlayerCharacter : public AGJCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGJPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual FVector GetPawnViewLocation() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character")
	TObjectPtr<UGJInteractionComponent> InteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character")
	TObjectPtr<UGJInventoryComponent> InventoryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character")
	TObjectPtr<USceneComponent> WeaponTransform;

	UPROPERTY()
	AGJWeapon* CurrentWeapon;

public:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Interact();
	void UsePrimaryAbility();
	void UseSecondaryAbility();

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(AGJWeapon* WeaponToEquip);

	UFUNCTION(BlueprintCallable)
	AGJWeapon* GetEquipedWeapon() const;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> HudWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> HudWidgetInstance;
};
