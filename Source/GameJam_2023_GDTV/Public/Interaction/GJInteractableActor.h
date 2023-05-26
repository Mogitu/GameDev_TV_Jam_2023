// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GJInteractionInterface.h"
#include "GameFramework/Actor.h"
#include "GJInteractableActor.generated.h"

UCLASS()
class GAMEJAM_2023_GDTV_API AGJInteractableActor : public AActor, public IGJInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGJInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	USoundBase* InteractSound;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FText InteractionText;

public:
	virtual FText GetInteractText_Implementation(APawn* InstigatorPawn) override;
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
