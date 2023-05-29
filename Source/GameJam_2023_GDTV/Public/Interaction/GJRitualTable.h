// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/GJInteractableActor.h"
#include "GJRitualTable.generated.h"

class UGJPopupWidget;
/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJRitualTable : public AGJInteractableActor
{
	GENERATED_BODY()

public:
	AGJRitualTable();

	virtual void BeginPlay() override;
	void ClearCollectedParts();
	void DisableAltar();
	void TryPlaceWeaponPart(APawn* InstigatorPawn);

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

	virtual FText GetInteractText_Implementation(APawn* InstigatorPawn) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Ritual")
	TObjectPtr<UStaticMeshComponent> RitualMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ritual")
	TSubclassOf<AActor> WeaponToSpawnClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ritual")
	TSubclassOf<UGJPopupWidget> PopupWidgetClass;

private:
	UPROPERTY()
	TMap<FName, TObjectPtr<AActor>> SpawnedParts;

	UPROPERTY()
	TMap<FName, FTransform> SocketTransforms;

	bool AllPartsCollected() const;

	bool bWeaponSpawned;
};
