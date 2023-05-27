#include "Character/GJMonsterCharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "Common/GJGameplayFunctionLibrary.h"
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

	SetSpeed(BaseSpeed);
}

void AGJMonsterCharacter::Attack()
{
	// Print "Player Attacked!"
	UE_LOG(LogTemp, Warning, TEXT("Player Attacked!"));
	// Get the player character reference
	AActor* PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	// Get Player's Max Health
	UGJGameplayFunctionLibrary::DamageActor(this, PlayerCharacter, 25.0f);
}

void AGJMonsterCharacter::OnPickupCollected()
{
}

void AGJMonsterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGJMonsterCharacter::OnHealthChanged_Implementation(AActor* InstigatorActor, UGJHealthComponent* OwningComp, float NewHealth,
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

void AGJMonsterCharacter::SetSpeed(float Speed)
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

void AGJMonsterCharacter::SetBaseSpeed(float Speed)
{
	BaseSpeed = Speed;
}

float AGJMonsterCharacter::GetSpeed()
{
	return GetCharacterMovement()->MaxWalkSpeed;
}

float AGJMonsterCharacter::GetBaseSpeed()
{
	return BaseSpeed;
}
AGJMonsterCharacter* AGJMonsterCharacter::GetMonsterCharacterReference()
{
	return this;
}


