// Fill out your copyright notice in the Description page of Project Settings.


#include "InputActionBindingList.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include  "EnhancedInputComponent.h"

void FWarriorInputActionBinding::Init(ACharacter* Character, UEnhancedInputComponent* InEnhancedInputComponent)
{
	const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(Character);
	check(AbilitySystemInterface);

	const UAbilitySystemComponent* AbilitySystemComponent = AbilitySystemInterface->GetAbilitySystemComponent();
	check(AbilitySystemComponent);

	BindingHandle = 0;

	if (!EnhancedInputComponent)
	{
		EnhancedInputComponent = InEnhancedInputComponent;
	}

	if (WarriorInputAction)
	{
		WarriorInputAction = NewObject<UWarriorInputAction>(EnhancedInputComponent, WarriorInputActionClass);
	}
	check(WarriorInputAction);

	WarriorInputAction->Init(Character);
	if (InputTag.IsValid())
	{
		WarriorInputAction->InputTag = InputTag;
	}

	BindInputAction();

	if (AbilitySystemComponent->HasMatchingGameplayTag(DisableInputTag))
	{
		if (bDisableInputNeedRemoveBinding)
		{
			RemoveBinding();
		}
		WarriorInputAction->bDisableInput = true;
	}
}

void FWarriorInputActionBinding::BindInputAction()
{
	if (BindingHandle == 0)
	{
		BindingHandle = EnhancedInputComponent->BindAction(InputAction, TriggerEvent, WarriorInputAction,
			&UWarriorInputAction::OnInputAction).GetHandle();
	}
}

void FWarriorInputActionBinding::RemoveBinding()
{
	EnhancedInputComponent->RemoveBindingByHandle(BindingHandle);
	BindingHandle = 0;
}

void UWarriorInputAction::OnInputAction(const FInputActionValue& InputActionValue)
{
}

void UWarriorInputAction::Init(ACharacter* InCharacter)
{
	Character = InCharacter;
}
