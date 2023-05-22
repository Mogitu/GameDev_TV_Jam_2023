// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/GJWeapon.h"

// Sets default values
AGJWeapon::AGJWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weaponmesh"));
	SetRootComponent(WeaponMesh);
	SetActorEnableCollision(false);
}

// Called when the game starts or when spawned
void AGJWeapon::BeginPlay()
{
	Super::BeginPlay();
}
