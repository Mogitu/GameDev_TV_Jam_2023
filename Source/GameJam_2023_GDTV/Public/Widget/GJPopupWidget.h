// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GJPopupWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class GAMEJAM_2023_GDTV_API UGJPopupWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetPopupText(FText Text);

	void StartTimer(float Duration);

protected:
	UPROPERTY(meta = (BindWidget))
   	TObjectPtr<UTextBlock> PopupTextBlock;	
};
