#include "Character/GJMonsterCharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "Common/GJHealthComponent.h"

AGJMonsterCharacter::AGJMonsterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGJMonsterCharacter::Attack()
{
	// Print "Player Attacked!"
	UE_LOG(LogTemp, Warning, TEXT("Player Attacked!"));
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
