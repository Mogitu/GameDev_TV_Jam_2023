// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GJAbility.generated.h"

class UGJAbilityComponent;
/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UGJAbility : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	FName AbilityName;

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	void StartAbility();

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	void StopAbility();

	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	bool CanStart(AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category = "Action")
	bool IsRunning() const;

protected:
	UPROPERTY()
	TObjectPtr<UGJAbilityComponent> OwningComponent;	
};
