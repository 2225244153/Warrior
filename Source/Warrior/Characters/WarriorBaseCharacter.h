// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UGameplayAbility;
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
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCapsuleComponent* AttackCapsule;

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AbilitySystem")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//用于添加GameplayTag，让角色可以通过GameplayTag来调用GA
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AbilitySystem")
	TArray<FGameplayTagContainer> GameplayTagContainers;

	//将GA添加进角色控件（初始化GA）
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> PreloadedAbilities;

	//在蓝图中动态添加Ability
	UFUNCTION(BlueprintCallable,Category="AbilitySystem")
	void GiveAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level = 1);

	//使用GA
	UFUNCTION(BlueprintCallable)
	void ActiveAbility(int32 TagIndex);

	

	
	
};
