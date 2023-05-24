// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GJInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGJInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEJAM_2023_GDTV_API IGJInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FText GetInteractText(APawn* InstigatorPawn); 
};
