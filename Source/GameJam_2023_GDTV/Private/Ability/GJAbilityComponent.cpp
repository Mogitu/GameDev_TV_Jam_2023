// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/GJAbilityComponent.h"

#include "Ability/GJAbility.h"

// Sets default values for this component's properties
UGJAbilityComponent::UGJAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGJAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UGJAbility> AbilityClass : DefaultAbilities)
	{
		AddAbility(GetOwner(), AbilityClass);
	}
}

void UGJAbilityComponent::AddAbility(AActor* Instigator, TSubclassOf<UGJAbility> AbilityClass)
{
	if (!ensure(AbilityClass))
	{
		return;
	}

	auto NewAbility = NewObject<UGJAbility>(GetOwner(), AbilityClass);
	if (ensure(NewAbility))
	{
		Abilities.Add(AbilityClass, NewAbility);

		if (NewAbility->bAutoStart && ensure(NewAbility->CanStart(Instigator)))
		{
			NewAbility->StartAbility(Instigator);
		}
	}
}

void UGJAbilityComponent::RemoveAbility(UGJAbility* AbilityToRemove)
{
	Abilities.Remove(AbilityToRemove->StaticClass());
}

bool UGJAbilityComponent::StartAbilityByName(AActor* Instigator, FName AbilityName)
{
	for (auto Ability : Abilities)
	{
		if (Ability.Value && Ability.Value->AbilityName == AbilityName)
		{
			if (!Ability.Value->CanStart(Instigator))
			{
				FString FailedMsg = FString::Printf(TEXT("Failed to run: %s"), *AbilityName.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FailedMsg);
				continue;
			}

			Ability.Value->StartAbility(Instigator);
			return true;
		}
	}
	return false;
}

bool UGJAbilityComponent::StopAbilityByName(AActor* Instigator, FName AbilityName)
{
	for (auto Ability : Abilities)
	{
		if (Ability.Value && Ability.Value->AbilityName == AbilityName)
		{
			if (Ability.Value->IsRunning())
			{
				Ability.Value->StopAbility(Instigator);
				return true;
			}
		}
	}
	return false;
}

UGJAbility* UGJAbilityComponent::GetAbility(TSubclassOf<UGJAbility> AbilityClass) const
{
	return Abilities[AbilityClass];
}

void UGJAbilityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	auto AbilitiesCopy = Abilities;
	for (auto Ability : AbilitiesCopy)
	{
		if (Ability.Value && Ability.Value->IsRunning())
		{
			Ability.Value->StopAbility(GetOwner());
		}
	}
	Super::EndPlay(EndPlayReason);
}
