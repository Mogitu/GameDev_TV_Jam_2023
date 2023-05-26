// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon/GJWeapon.h"

#include "Blueprint/UserWidget.h"
#include "Common/GJGameplayFunctionLibrary.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGJWeapon::AGJWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weaponmesh"));
	SetRootComponent(WeaponMesh);
	MaxAmmo = 5;
	DamageAmount = 25;
	ShotDistance = 5000;
}

// Called when the game starts or when spawned
void AGJWeapon::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = 0;
}

UStaticMeshComponent* AGJWeapon::GetWeaponMesh()
{
	return WeaponMesh;
}

void AGJWeapon::Equip(AActor* ActorThatEquips, USceneComponent* Comp)
{
	OwningCharacter = Cast<APawn>(ActorThatEquips);
	GetWeaponMesh()->SetSimulatePhysics(false);
	SetActorEnableCollision(false);
	GetRootComponent()->AttachToComponent(Comp, FAttachmentTransformRules::SnapToTargetIncludingScale);
	if (WeaponDisplayWidgetClass)
	{
		WeaponDisplayWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WeaponDisplayWidgetClass);
		WeaponDisplayWidgetInstance->AddToViewport();
	}
}

void AGJWeapon::Fire()
{
	if (CurrentAmmo <= 0)
	{
		LogOnScreen(this, "NO AMMO LEFT");
		return;
	}

	FVector TraceDirection = OwningCharacter->GetControlRotation().Vector();
	FVector TraceStart = OwningCharacter->GetPawnViewLocation();
	FVector TraceEnd = TraceStart + (TraceDirection * ShotDistance);
	FHitResult HitResult;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwningCharacter);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Pawn, Params))
	{
		AActor* HitActor = HitResult.GetActor();
		UGJGameplayFunctionLibrary::DamageActor(OwningCharacter, HitActor, DamageAmount);
	}
	DepleteAmmo(1);
	if (FireSound)
	{
		UGameplayStatics::SpawnSoundAttached(FireSound, GetRootComponent());
	}
}

void AGJWeapon::AddAmmo(int32 Amount)
{
	CurrentAmmo = FMath::Clamp(CurrentAmmo + Amount, 0, MaxAmmo);
	OnAmmoChanged.Broadcast(CurrentAmmo);
}

void AGJWeapon::DepleteAmmo(int32 Amount)
{
	CurrentAmmo = FMath::Clamp(CurrentAmmo - Amount, 0, MaxAmmo);
	OnAmmoChanged.Broadcast(CurrentAmmo);
}
