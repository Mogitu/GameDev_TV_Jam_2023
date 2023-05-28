// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GJHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, UGJHealthComponent*,
                                              OwningComp, float, NewHealth, float, Delta);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEJAM_2023_GDTV_API UGJHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Health")
	static UGJHealthComponent* GetHealthComponent(AActor* FromActor);

	// Sets default values for this component's properties
	UGJHealthComponent();

	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category="Health")
	void ApplyHealthChange(AActor* Instigator, float Delta);

	UFUNCTION(BlueprintCallable)
	float GetHealthPercentage() const;

	UFUNCTION(BlueprintCallable)
	float GetHealthFraction() const;

	UFUNCTION(BlueprintCallable)
	bool IsDead()const;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Health")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	float MaxHealth;
};
