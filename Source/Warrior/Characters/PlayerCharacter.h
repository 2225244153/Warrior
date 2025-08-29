// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseCharacter.h"
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

	virtual void BeginPlay() override;


	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	//普通按键的绑定
	UFUNCTION()
	void JumpStart();

	UFUNCTION()
	void JumpEnd();
	
	UFUNCTION()
	void Attack();
	
	UFUNCTION()
	void MoveForward(float X);

	UFUNCTION()
	void MoveRight(float X);

	UFUNCTION()
	void TurnRight(float X);

	UFUNCTION()
	void LookUp(float X);

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	

};
