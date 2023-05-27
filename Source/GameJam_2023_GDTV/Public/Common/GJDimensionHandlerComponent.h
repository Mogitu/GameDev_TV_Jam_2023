// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameMode/GJGameMode.h"
#include "GJDimensionHandlerComponent.generated.h"

USTRUCT(BlueprintType)
struct FDimensionSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DimensionSettings")
	bool bIsHidden;		
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAM_2023_GDTV_API UGJDimensionHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGJDimensionHandlerComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnDimensionSwitch(EDimension NewDimension);

	UFUNCTION(BlueprintCallable)
	void SetDimensionSettings(EDimension NewDimension);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dimension")
	FDimensionSettings NormalDimensionSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dimension")
	FDimensionSettings GhostDimensionSettings;

private:
	void ApplyDimensionSettings(FDimensionSettings Settings);
	
};