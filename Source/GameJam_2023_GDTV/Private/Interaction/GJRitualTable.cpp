// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/GJRitualTable.h"

#include "Definitions.h"
#include "Character/GJInventoryComponent.h"
#include "Common/GJDimensionHandlerComponent.h"
#include "Common/GJGameplayFunctionLibrary.h"

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
		if (Inventory->GetCollectedItems().IsEmpty())
		{
			auto Widget = UGJGameplayFunctionLibrary::CreatePopup(GetWorld()->GetFirstPlayerController(),
			                                                      PopupWidgetClass,
			                                                      FText::FromString("Collect weapon parts first"));
			Widget->AddToViewport();
			return;
		}
		for (auto Pair : SocketTransforms)
		{
			if (SpawnedParts.Contains(Pair.Key))continue;

			if (auto Item = Inventory->GetDataWithKey(Pair.Key))
			{
				FTransform Transform = Pair.Value;
				AActor* Spawned = GetWorld()->SpawnActorDeferred<AActor>(Item->PickupClass, Transform);
				if (auto DimensionComponentPart = Spawned->GetComponentByClass<UGJDimensionHandlerComponent>())
				{
					auto OwnDim = GetComponentByClass<UGJDimensionHandlerComponent>();
					DimensionComponentPart->ChangeSettingsForDimension(NormalDimension, {
						                                                   OwnDim->GetNormalDimensionSettings().
						                                                   bIsHidden,
						                                                   true
					                                                   });
					DimensionComponentPart->ChangeSettingsForDimension(GhostDimension, {
						                                                   OwnDim->GetGhostDimensionSettings().
						                                                   bIsHidden,
						                                                   true
					                                                   });
				}
				Spawned->SetActorEnableCollision(false);
				Spawned->FinishSpawning(Transform);
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
		Super::Interact_Implementation(InstigatorPawn);
		FTransform Transform(GetActorRotation(), GetActorLocation() + FVector::UpVector * 200);

		//spawn the weapon
		AActor* WeaponSpawn = GetWorld()->SpawnActorDeferred<AActor>(WeaponToSpawnClass, Transform);
		if (auto WeaponDimensionComp = WeaponSpawn->GetComponentByClass<UGJDimensionHandlerComponent>())
		{
			if (auto OwnDimensionComp = GetComponentByClass<UGJDimensionHandlerComponent>())
			{
				WeaponDimensionComp->ChangeSettingsForDimension(GhostDimension, {
					                                                OwnDimensionComp->GetGhostDimensionSettings().
					                                                bIsHidden,
					                                                true
				                                                });
				WeaponDimensionComp->ChangeSettingsForDimension(NormalDimension, {
					                                                OwnDimensionComp->GetNormalDimensionSettings().
					                                                bIsHidden,
					                                                false
				                                                });
			}
		}
		DisableAltar();
		ClearCollectedParts();

		bWeaponSpawned = true;
		WeaponSpawn->FinishSpawning(Transform);
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
