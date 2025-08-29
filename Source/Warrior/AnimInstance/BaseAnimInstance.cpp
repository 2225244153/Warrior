// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/AnimInstance/BaseAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Warrior/Characters/WarriorBaseCharacter.h"



void UBaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BaseCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (BaseCharacter)
	{
		Speed =  BaseCharacter->GetVelocity().Length();
		
		Direction = UKismetAnimationLibrary::CalculateDirection(BaseCharacter->GetVelocity(),BaseCharacter->GetActorRotation());

		bIsJumping = BaseCharacter->GetCharacterMovement()->IsFalling();
	}
}

void UBaseAnimInstance::PrintLog(FString Str)
{
	UE_LOG(LogTemp,Error,TEXT("%s"),*Str);
}
