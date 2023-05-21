// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "GJAbilityComponent.generated.h"

class UGJAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityStateChanged, UGJAbilityComponent*, OwningComp, UGJAbility*,
                                             Ability);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEJAM_2023_GDTV_API UGJAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGJAbilityComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	FGameplayTagContainer ActiveGameplayTags;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void AddAbility(AActor* Instigator, TSubclassOf<UGJAbility> AbilityClass);

	void RemoveAbility(UGJAbility* AbilityToRemove);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	UGJAbility* GetAbility(TSubclassOf<UGJAbility> AbilityClass) const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool StartAbilityByName(AActor* Instigator, FName AbilityName);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool StopAbilityByName(AActor* Instigator, FName AbilityName);

	UPROPERTY(BlueprintAssignable)
	FOnAbilityStateChanged OnAbilityStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityStateChanged OnAbilityStopped;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGJAbility>> DefaultAbilities;

	UPROPERTY(BlueprintReadOnly)
	TMap<TSubclassOf<UGJAbility>, TObjectPtr<UGJAbility>> Abilities;
};
