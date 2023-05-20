// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GJCharacter.generated.h"

class UGJHealthComponent;

UCLASS()
class GAMEJAM_2023_GDTV_API AGJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGJCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGJHealthComponent> HealthComponent;
};
