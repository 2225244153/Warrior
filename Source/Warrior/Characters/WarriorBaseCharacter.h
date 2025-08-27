// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "WarriorBaseCharacter.generated.h"

struct FGameplayTagContainer;
class UAbilitySystemComponent;

UCLASS()
class WARRIOR_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorBaseCharacter();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AbilitySystem")
	UAbilitySystemComponent* AbilitySystemComponent;

	virtual void BeginPlay() override;
public:
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AbilitySystem")
	TArray<FGameplayTagContainer> GameplayTagContainers;

	UFUNCTION(BlueprintCallable)
	void ActiveAbility(int32 TagIndex);
	
	
};
