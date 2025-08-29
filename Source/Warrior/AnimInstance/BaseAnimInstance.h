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
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AWarriorBaseCharacter* BaseCharacter;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float Speed;

	UPROPERTY(blueprintReadWrite,EditAnywhere)
	float Direction;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool bIsJumping;

	UFUNCTION(BlueprintCallable)
	void PrintLog(FString Str = TEXT("AnimInstance"));

	
	
};
