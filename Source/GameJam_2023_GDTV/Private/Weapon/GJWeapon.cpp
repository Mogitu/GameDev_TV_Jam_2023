// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/GJWeapon.h"

#include "Common/GJGameplayFunctionLibrary.h"
#include "Common/GJHealthComponent.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"

// Sets default values
AGJWeapon::AGJWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weaponmesh"));
	SetRootComponent(WeaponMesh);
}

// Called when the game starts or when spawned
void AGJWeapon::BeginPlay()
{
	Super::BeginPlay();
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
}

void AGJWeapon::Fire()
{
	FVector TraceDirection = OwningCharacter->GetControlRotation().Vector();
	FVector TraceStart = OwningCharacter->GetPawnViewLocation();
	FVector TraceEnd = TraceStart + (TraceDirection * 5000);
	FHitResult HitResult;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwningCharacter);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Pawn, Params))
	{
		AActor* HitActor = HitResult.GetActor();
		UGJGameplayFunctionLibrary::DamageActor(OwningCharacter, HitActor, 10);
		LogOnScreen(this, "YES" + HitActor->GetName());
	}
}
