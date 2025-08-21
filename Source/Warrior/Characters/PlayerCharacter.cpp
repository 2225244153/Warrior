// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/Characters/PlayerCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&APlayerCharacter::JumpStart);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Released,this,&APlayerCharacter::JumpEnd);

	PlayerInputComponent->BindAxis(TEXT("MoveForward/Backward"),this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight/Left"),this,&APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("TurnRight/LeftMouse"),this,&APlayerCharacter::TurnRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp/DownMouse"),this,&APlayerCharacter::LookUp);
}

void APlayerCharacter::JumpStart()
{
	Jump();
}

void APlayerCharacter::JumpEnd()
{
	StopJumping();
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
