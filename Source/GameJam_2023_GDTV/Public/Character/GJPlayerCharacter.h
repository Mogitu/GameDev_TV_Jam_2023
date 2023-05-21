// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GJCharacter.h"
#include "GJPlayerCharacter.generated.h"

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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Interact();
	void UsePrimaryAbility();
	void UseSecondaryAbility();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, Category="Character")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, Category="Character")
	TObjectPtr<UGJInteractionComponent> InteractionComponent;

	UPROPERTY(VisibleAnywhere, Category="Character")
	TObjectPtr<UGJInventoryComponent> InventoryComponent;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> HudWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> HudWidgetInstance;
};
