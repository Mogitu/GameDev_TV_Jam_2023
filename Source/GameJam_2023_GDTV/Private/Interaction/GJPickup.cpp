// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJPickup.h"
#include "Character/GJInventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Character/GJMonsterCharacter.h"

AGJPickup::AGJPickup()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SetRootComponent(CollisionSphere);

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(GetRootComponent());
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

void AGJPickup::Interact_Implementation(APawn* InstigatorPawn)
{
	Super::Interact_Implementation(InstigatorPawn);
	if (auto Inventory = InstigatorPawn->FindComponentByClass<UGJInventoryComponent>())
	{
		if (PickupData)
		{
			Inventory->CollectItem(PickupData);
		}

		if (MonsterReference != nullptr)
		{
			MonsterReference->SetSpeed(MonsterReference->GetSpeed() + 30.0f);
			MonsterReference->SetBaseSpeed(MonsterReference->GetBaseSpeed() + 30.0f);
		}
	}
	Destroy();
}
