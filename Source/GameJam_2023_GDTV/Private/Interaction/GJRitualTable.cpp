// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJRitualTable.h"

#include "Definitions.h"
#include "Character/GJInventoryComponent.h"

AGJRitualTable::AGJRitualTable()
{
	RitualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RitualMesh"));
	SetRootComponent(RitualMesh);
}

void AGJRitualTable::BeginPlay()
{
	Super::BeginPlay();
	for (auto Name : RitualMesh->GetAllSocketNames())
	{
		auto Transform = RitualMesh->GetSocketTransform(Name);
		SocketTransforms.Add(Name, Transform);
	}
}

void AGJRitualTable::ClearCollectedParts()
{
	for (auto part : SpawnedParts)
	{
		part.Value->Destroy();
	}
	SpawnedParts.Empty();
}

void AGJRitualTable::DisableAltar()
{
	RitualMesh->SetCollisionObjectType(ECC_WorldStatic);
	RitualMesh->SetOverlayMaterial(nullptr);
}

void AGJRitualTable::TryPlaceWeaponPart(APawn* InstigatorPawn)
{
	if (auto Inventory = InstigatorPawn->GetComponentByClass<UGJInventoryComponent>())
	{
		for (auto Pair : SocketTransforms)
		{
			if (SpawnedParts.Contains(Pair.Key))continue;

			if (auto Item = Inventory->GetDataWithKey(Pair.Key))
			{
				FTransform Transform = Pair.Value;
				AActor* Spawned = GetWorld()->SpawnActor<AActor>(Item->PickupClass, Transform.GetLocation(),
				                                                 Transform.GetRotation().Rotator());
				Spawned->SetActorEnableCollision(false);
				SpawnedParts.Add(Item->Name, Spawned);
			}
		}
	}
}

void AGJRitualTable::Interact_Implementation(APawn* InstigatorPawn)
{
	//nothing to do.
	if (bWeaponSpawned)return;

	if (AllPartsCollected())
	{
		//spawn the weapon
		GetWorld()->SpawnActor<AActor>(WeaponToSpawnClass,
		                               GetActorLocation() + FVector::UpVector * 200,
		                               GetActorRotation());
		DisableAltar();
		ClearCollectedParts();
		bWeaponSpawned = true;
		return;
	}

	TryPlaceWeaponPart(InstigatorPawn);
}

FText AGJRitualTable::GetInteractText_Implementation(APawn* InstigatorPawn)
{
	if (AllPartsCollected())
	{
		return FText::FromString("Perform Ritual");
	}
	return FText::FromString("Place Weapon Parts");
}

bool AGJRitualTable::AllPartsCollected() const
{
	return SpawnedParts.Num() == SocketTransforms.Num();
}