// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/GJGameplayFunctionLibrary.h"

#include "Blueprint/UserWidget.h"
#include "Common/GJHealthComponent.h"
#include "Widget/GJUserWidget.h"

bool UGJGameplayFunctionLibrary::DamageActor(AActor* DamageCauser, AActor* TargetActor, float DamageAmount)
{
	if (UGJHealthComponent* HealthComponent = UGJHealthComponent::GetHealthComponent(TargetActor))
	{
		HealthComponent->ApplyHealthChange(DamageCauser, -DamageAmount);
		return true;
	}
	return false;
}

bool UGJGameplayFunctionLibrary::HealActor(AActor* HealerActor, AActor* TargetActor, float HealAmount)
{
	if (UGJHealthComponent* HealthComponent = UGJHealthComponent::GetHealthComponent(TargetActor))
	{
		HealthComponent->ApplyHealthChange(HealerActor, HealAmount);
		return true;
	}
	return false;
}

UGJPopupWidget* UGJGameplayFunctionLibrary::CreatePopup(APlayerController* Owner, TSubclassOf<UGJPopupWidget> WidgetClass, FText Text,
	float Duration)
{
	UGJPopupWidget* Widget = CreateWidget<UGJPopupWidget>(Owner, WidgetClass);
	Widget->SetPopupText(Text);
	Widget->StartTimer(Duration);
	return Widget;
}
