/*
 *File that stores any structs that the game could need. Since they are small a single header makes sense for now
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Definitions.generated.h"

UCLASS(BlueprintType)
class UPickupData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pickup Data")
	FName Name;	
};

UCLASS(BlueprintType)
class UWeaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Data")
	UStaticMeshComponent* WeaponMesh;	
};
