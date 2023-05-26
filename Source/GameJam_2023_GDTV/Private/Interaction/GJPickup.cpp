// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJPickup.h"
#include "Character/GJInventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Character/GJMonsterCharacter.h"

AGJPickup::AGJPickup()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	SetRootComponent(CollisionSphere);

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(GetRootComponent());
}

void AGJPickup::BeginPlay()
{
	Super::BeginPlay();
}

void AGJPickup::Interact_Implementation(APawn* InstigatorPawn)
{
	if (auto Inventory = InstigatorPawn->FindComponentByClass<UGJInventoryComponent>())
	{
		Inventory->CollectItem(PickupData);
		if (MonsterReference != nullptr)
		{
			MonsterReference->IncreaseSpeed();
		}

	}
	Destroy();
}
