// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GJPopupWidget.h"

#include "Components/TextBlock.h"
#include "GameJam_2023_GDTV/GameJam_2023_GDTV.h"

void UGJPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();	
}

void UGJPopupWidget::SetPopupText(FText Text)
{
	PopupTextBlock->SetText(Text);
}

void UGJPopupWidget::StartTimer(float Duration)
{
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &UGJPopupWidget::RemoveFromParent, Duration, false);
}
