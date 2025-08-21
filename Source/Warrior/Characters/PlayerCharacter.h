// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Warrior/Characters/WarriorBaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API APlayerCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

	APlayerCharacter();

protected:

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void JumpStart();

	UFUNCTION()
	void JumpEnd();
	
	UFUNCTION()
	void MoveForward(float X);

	void MoveRight(float X);

	UFUNCTION()
	void TurnRight(float X);

	UFUNCTION()
	void LookUp(float X);
	
};
