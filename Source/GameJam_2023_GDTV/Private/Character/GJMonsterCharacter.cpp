#include "Character/GJMonsterCharacter.h"

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
