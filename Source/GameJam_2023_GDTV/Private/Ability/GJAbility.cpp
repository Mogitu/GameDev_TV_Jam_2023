// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/GJAbility.h"

#include "Ability/GJAbilityComponent.h"

UGJAbility::UGJAbility()
{
	OwningComponent = Cast<UGJAbilityComponent>(GetOuter());
}

bool UGJAbility::CanStart_Implementation(AActor* Instigator)
{
	if (IsRunning())
	{
		return false;
	}

	UGJAbilityComponent* Comp = OwningComponent;

	if (Comp->ActiveGameplayTags.HasAny(BlockedTags))
	{
		return false;
	}

	return true;
}

void UGJAbility::StartAbility_Implementation(AActor* Instigator)
{
	UGJAbilityComponent* Comp = OwningComponent;
	Comp->ActiveGameplayTags.AppendTags(GrantsTags);
	TimeStarted = GetWorld()->TimeSeconds;

	bIsRunning = true;

	OwningComponent->OnAbilityStarted.Broadcast(OwningComponent, this);
}

void UGJAbility::StopAbility_Implementation(AActor* Instigator)
{
	UGJAbilityComponent* Comp = OwningComponent;
	Comp->ActiveGameplayTags.RemoveTags(GrantsTags);

	bIsRunning = false;

	OwningComponent->OnAbilityStopped.Broadcast(OwningComponent, this);
}

bool UGJAbility::IsRunning() const
{
	return bIsRunning;
}
