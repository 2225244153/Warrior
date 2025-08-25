// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
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
	//PlayerInputComponent->BindAxis(TEXT("LookUp/DownMouse"),this,&APlayerCharacter::LookUp);

	
	
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
	UAnimMontage* Melee = LoadObject<UAnimMontage>(nullptr,TEXT("/Script/Engine.AnimMontage'/Game/A_Game/Animation/Montage/AM_Attack.AM_Attack'"));
	PlayAnimMontage(Melee);
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


