// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/Characters/WarriorBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "MonsterCharacter.h"


AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
}

void AWarriorBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystemComponent)
	{
		//AbilitySystemComponent->GiveAbility();
	}
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; 
}
