// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "InputAction.h"
#include "InputActionBindingList.generated.h"

class UWarriorInputAction;

USTRUCT(BlueprintType)
struct FWarriorInputActionBinding
{
	GENERATED_BODY()
public:
	/**
	 * @brief IA
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InputAction;

	/**
	 * @brief 输入回调逻辑
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TSubclassOf<UWarriorInputAction> WarriorInputActionClass;

	/**
	 * @brief 触发方式
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	ETriggerEvent TriggerEvent;

	/**
	 * @brief 输入tag，当IA激活是会激活对应的Tag
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	FGameplayTag InputTag;

	/**
	 * @brief 屏蔽该输入的Tag
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DisableInput")
	FGameplayTag DisableInputTag;

	/**
	 * @brief 是否需要移除绑定
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DisableInput")
	bool bDisableInputNeedRemoveBinding = false;
	
	/**
	 * @brief 保存的实例
	 */
	UPROPERTY()
	UWarriorInputAction* WarriorInputAction;

	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent;

	int32 BindingHandle = 0;

	void Init(ACharacter* Character, UEnhancedInputComponent* InEnhancedInputComponent);

	void BindInputAction();

	void RemoveBinding();
};

/**
 * 
 */
UCLASS()
class WARRIOR_API UInputActionBindingList : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FWarriorInputActionBinding> InputActionBindingList;
};

UCLASS()
class WARRIOR_API UWarriorInputAction : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief 输入回调
	 * @param InputActionValue
	 */
	UFUNCTION()
	virtual void OnInputAction(const FInputActionValue& InputActionValue);

	/**
	 * @brief 初始化
	 * @param InCharacter
	 */
	virtual void Init(ACharacter* InCharacter);

	UPROPERTY()
	FGameplayTag InputTag;

	UPROPERTY()
	bool bDisableInput = false;

	UPROPERTY()
	ACharacter* Character;
};
