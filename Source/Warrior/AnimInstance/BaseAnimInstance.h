// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

class AWarriorBaseCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
public:
	UPROPERTY()
	AWarriorBaseCharacter* BaseCharacter;

	UPROPERTY(BlueprintReadWrite)
	float Speed;

	UPROPERTY(blueprintReadWrite)
	float Direction;

	UPROPERTY(BlueprintReadWrite)
	bool bIsJumping;

	
	
};
