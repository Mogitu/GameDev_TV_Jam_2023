// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJWeaponPartPickup.h"

#include "Common/GJDimensionHandlerComponent.h"

AGJWeaponPartPickup::AGJWeaponPartPickup()
{
	DimensionHandlerComponent = CreateDefaultSubobject<UGJDimensionHandlerComponent>(TEXT("DimensionHandler"));
}

void AGJWeaponPartPickup::BeginPlay()
{
	Super::BeginPlay();
}
