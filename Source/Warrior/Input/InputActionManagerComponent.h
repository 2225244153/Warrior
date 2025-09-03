// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "InputActionManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UInputActionManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInputActionManagerComponent();

private:
	//void InitInputAction(APlayerController* InController);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InputAction")
	TObjectPtr<u>*/

};
