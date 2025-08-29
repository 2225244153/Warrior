// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Warrior/Common/ConstText.h"

APlayerCharacter::APlayerCharacter()
{

}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AttackCapsule->OnComponentBeginOverlap.AddDynamic(this,&APlayerCharacter::OnComponentBeginOverlap);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//普通按鍵綁定
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&APlayerCharacter::JumpStart);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Released,this,&APlayerCharacter::JumpEnd);

	PlayerInputComponent->BindAction(TEXT("Attack"),IE_Pressed,this,&APlayerCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("MoveForward/Backward"),this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight/Left"),this,&APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("TurnRight/LeftMouse"),this,&APlayerCharacter::TurnRight);
	

	
	
}

void APlayerCharacter::JumpStart()
{
	Jump();
}

void APlayerCharacter::JumpEnd()
{
	StopJumping();
}

void APlayerCharacter::Attack()
{
	ActiveAbility(0);
}

void APlayerCharacter::MoveForward(float X)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(FRotator(0.0, GetControlRotation().Yaw,0.0 )),X,false);
}

void APlayerCharacter::MoveRight(float X)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(FRotator(0.0,GetControlRotation().Yaw, 0.0 )),X,false);
}

void APlayerCharacter::TurnRight(float X)
{
	AddControllerYawInput(X);	
}

void APlayerCharacter::LookUp(float X)
{
	AddControllerPitchInput(X);
}

void APlayerCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->GetClass() != this->GetClass())
	{
		if (AWarriorBaseCharacter* BaseCharacter = Cast<AWarriorBaseCharacter>(OtherActor))
		{
			UGameplayEffect* MeleeDamage = LoadObject<UGameplayEffect>(nullptr,TEXT("/Script/Engine.Blueprint'/Game/A_Game/Abilities/FirstMelee/GE_Melee_Damage.GE_Melee_Damage'"));
			
		}
	}
}


