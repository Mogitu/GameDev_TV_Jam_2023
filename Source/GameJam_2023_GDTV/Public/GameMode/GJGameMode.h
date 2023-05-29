// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GJGameMode.generated.h"

UENUM(BlueprintType)
enum EDimension : uint8
{
	NormalDimension UMETA(DisplayName = "Normal Dimension"),
	GhostDimension UMETA(DisplayName = "Ghost Dimension")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDimensionSwitch, EDimension, NewDimension);

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API AGJGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AGJGameMode();

	void OnActorKilled(AActor* Victim, AActor* Killer);

	//Specifically change to a certain dimension
	UFUNCTION(BlueprintCallable)
	void SetDimension(EDimension NewDimension);

	//just toggle back and forth between ghost and normal dimension
	UFUNCTION(BlueprintCallable)
	void ToggleDimension();

	UFUNCTION(BlueprintCallable)
	EDimension GetCurrentDimension() const;

	UPROPERTY(BlueprintAssignable)
	FOnDimensionSwitch OnDimensionSwitch;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Music")
	float MusicFadeDuration;

	UPROPERTY(VisibleAnywhere, Category="Music")
	TObjectPtr<UAudioComponent> NormalAudioComp;

	UPROPERTY(VisibleAnywhere, Category="Music")
	TObjectPtr<UAudioComponent> GhostAudioComp;

	UPROPERTY(EditDefaultsOnly, Category="GameEnd")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="GameEnd")
	TSubclassOf<UUserWidget> GameWinWidgetClass;

	void Init();

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnGameEnd();
	
	EDimension CurrentDimension;

	FTimerHandle GameEndTimerHandle;

	TSubclassOf<UUserWidget> WidgetClassToSpawn;
};
