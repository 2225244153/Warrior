// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/Characters/WarriorBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Warrior/GameplayAbility/BaseGameplayAbility.h"


AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	AttackCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackCapsule"));
	if (AttackCapsule != nullptr)
	{
		AttackCapsule->SetupAttachment(GetMesh(),FName(TEXT("weapon_r")));
		AttackCapsule->SetRelativeLocation(FVector(0.0f,-36.0f,0.0f));
		AttackCapsule->SetRelativeRotation(FRotator(0.0f,0.0f,-90.0f));
		AttackCapsule->SetRelativeScale3D(FVector(1.0f,0.205f,0.83f));
	}
}

void AWarriorBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystemComponent)
	{
		if (PreloadedAbilities.Num() > 0)
		{
			for (int32 i = 0; i < PreloadedAbilities.Num(); i++)
			{
				if (PreloadedAbilities[i])
				{
					AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(PreloadedAbilities[i].GetDefaultObject(),1));
				}
			}
		}
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}



UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; 
}

void AWarriorBaseCharacter::ActiveAbility(int32 TagIndex)
{
	AbilitySystemComponent->TryActivateAbilitiesByTag(GameplayTagContainers[TagIndex]);
}

void AWarriorBaseCharacter::GiveAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level)
{
	if (AbilitySystemComponent)
	{
		if (Ability)
		{
			AbilitySystemComponent->GiveAbility(Ability);
		}
	}
}
