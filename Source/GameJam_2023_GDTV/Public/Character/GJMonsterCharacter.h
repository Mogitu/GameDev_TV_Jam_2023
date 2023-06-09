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
	AGJMonsterCharacter* GetMonsterCharacterReference();
	void Attack();
	void SetSpeed(float Speed);
	void SetBaseSpeed(float Speed);
	float GetSpeed();
	float GetBaseSpeed();


	float BaseSpeed = 300.f;

	UFUNCTION()
	void OnPickupCollected();

private:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	

protected:
	virtual void OnHealthChanged_Implementation(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
	                             float Delta) override;

	
};
