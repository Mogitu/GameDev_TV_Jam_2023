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
	void IncreaseSpeed();

	UFUNCTION()
	void OnPickupCollected();

private:
	virtual void Tick(float DeltaTime) override;
	//OnBeginPlay
	virtual void BeginPlay() override;
	

protected:
	virtual void OnHealthChanged(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
	                             float Delta) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Monster")
	float SpeedFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Monster")
	float BaseSpeed;

	
};
