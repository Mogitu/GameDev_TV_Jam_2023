// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GJCharacter.h"
#include "Ability/GJAbilityComponent.h"
#include "Common/GJHealthComponent.h"

// Sets default values
AGJCharacter::AGJCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UGJHealthComponent>(TEXT("HealthComponent"));
	AbilityComponent = CreateDefaultSubobject<UGJAbilityComponent>(TEXT("AbilityComponent"));
}

void AGJCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	HealthComponent->OnHealthChanged.AddDynamic(this, &AGJCharacter::OnHealthChanged);
}

void AGJCharacter::OnHealthChanged(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
                                   float Delta)
{
}
