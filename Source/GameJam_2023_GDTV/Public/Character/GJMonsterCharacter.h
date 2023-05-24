// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GJCharacter.h"
#include "GJMonsterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJMonsterCharacter : public AGJCharacter
{
	GENERATED_BODY()

public:
	AGJMonsterCharacter();
	void Attack();

private:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void OnHealthChanged(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
	                             float Delta) override;
};
