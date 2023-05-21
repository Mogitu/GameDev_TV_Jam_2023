// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "GJAbility.generated.h"

class UGJAbilityComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class GAMEJAM_2023_GDTV_API UGJAbility : public UObject
{
	GENERATED_BODY()

public:
	UGJAbility();

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	FName AbilityName;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	bool bAutoStart;

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	void StartAbility(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	void StopAbility(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	bool CanStart(AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool IsRunning() const;

protected:
	UPROPERTY()
	TObjectPtr<UGJAbilityComponent> OwningComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer GrantsTags;

	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer BlockedTags;

	float TimeStarted;

	bool bIsRunning;
};
