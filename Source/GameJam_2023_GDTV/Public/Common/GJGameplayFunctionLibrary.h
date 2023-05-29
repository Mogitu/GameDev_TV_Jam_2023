// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/GJPopupWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GJGameplayFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UGJGameplayFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool DamageActor(AActor* DamageCauser, AActor* TargetActor, float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool HealActor(AActor* HealerActor, AActor* TargetActor, float HealAmount);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static UGJPopupWidget* CreatePopup(APlayerController* Owner, TSubclassOf<UGJPopupWidget> WidgetClass, FText Text, float Duration = 3.0f);
};
