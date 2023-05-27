// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GJDimensionHandlerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAM_2023_GDTV_API UGJDimensionHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGJDimensionHandlerComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnDimensionSwitch(bool bGhostDimensionActive);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Dimension")
	bool bInitiallyEnabled;



		



};
