#include "Character/GJMonsterCharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "Common/GJHealthComponent.h"
#include "Character/GJPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AGJMonsterCharacter::AGJMonsterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
}

void AGJMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();
	SpeedFactor = 1.25f;
	BaseSpeed = 300.0f;

	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}

void AGJMonsterCharacter::Attack()
{
	// Print "Player Attacked!"
	UE_LOG(LogTemp, Warning, TEXT("Player Attacked!"));
	IncreaseSpeed();
}

void AGJMonsterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGJMonsterCharacter::OnHealthChanged(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
                                          float Delta)
{
	if (NewHealth <= 0.0f && Delta < 0.0f)
	{
		AAIController* AIC = Cast<AAIController>(GetController());
		if (AIC)
		{
			AIC->GetBrainComponent()->StopLogic("Killed");
		}
		Destroy();
	}
}

void AGJMonsterCharacter::IncreaseSpeed()
{
	BaseSpeed *= SpeedFactor;
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}
AGJMonsterCharacter* AGJMonsterCharacter::GetMonsterCharacterReference()
{
	return this;
}
