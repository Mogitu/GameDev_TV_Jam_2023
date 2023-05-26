// Fill out your copyright notice in the Description page of Project Settings.

#include "Character\GJPlayerCharacter.h"

#include "Ability/GJAbilityComponent.h"
#include "Camera/CameraComponent.h"
#include "Character/GJInventoryComponent.h"
#include "Components/CapsuleComponent.h"
#include "Interaction/GJInteractionComponent.h"
#include "Weapon/GJWeapon.h"
#include "Widget/GJUserWidget.h"

// Sets default values
AGJPlayerCharacter::AGJPlayerCharacter()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->bUsePawnControlRotation = true;

	InteractionComponent = CreateDefaultSubobject<UGJInteractionComponent>(TEXT("Interaction Component"));
	InventoryComponent = CreateDefaultSubobject<UGJInventoryComponent>(TEXT("Inventory Component"));

	WeaponTransform = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponTransform"));
	WeaponTransform->SetupAttachment(CameraComponent);
}

// Called when the game starts or when spawned
void AGJPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (HudWidgetClass != nullptr)
	{
		HudWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
		HudWidgetInstance->AddToViewport();
	}
}

FVector AGJPlayerCharacter::GetPawnViewLocation() const
{
	return CameraComponent->GetComponentLocation();
}

void AGJPlayerCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGJPlayerCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGJPlayerCharacter::Turn(float Value)
{
	if (Value != 0.0f)
	{
		AddControllerYawInput(Value);
	}
}

void AGJPlayerCharacter::LookUp(float Value)
{
	if (Value != 0.0f)
	{
		AddControllerPitchInput(Value);
	}
}

void AGJPlayerCharacter::Interact()
{
	InteractionComponent->Interact();
}

void AGJPlayerCharacter::UsePrimaryAbility()
{
	if (IsValid(CurrentWeapon))
	{
		CurrentWeapon->Fire();
	}
	//AbilityComponent->StartAbilityByName(this, TEXT("PrimaryAbility"));
}

void AGJPlayerCharacter::UseSecondaryAbility()
{
	AbilityComponent->StartAbilityByName(this, TEXT("SecondaryAbility"));
}

void AGJPlayerCharacter::EquipWeapon(AGJWeapon* WeaponToEquip)
{
	WeaponToEquip->Equip(this, WeaponTransform);
	CurrentWeapon = WeaponToEquip;
}

AGJWeapon* AGJPlayerCharacter::GetEquipedWeapon() const
{
	return CurrentWeapon;
}

// Called to bind functionality to input
void AGJPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGJPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGJPlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AGJPlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AGJPlayerCharacter::LookUp);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGJPlayerCharacter::Interact);
	PlayerInputComponent->BindAction("PrimaryAbility", IE_Pressed, this, &AGJPlayerCharacter::UsePrimaryAbility);
	PlayerInputComponent->BindAction("SecondaryAbility", IE_Pressed, this, &AGJPlayerCharacter::UseSecondaryAbility);
}
