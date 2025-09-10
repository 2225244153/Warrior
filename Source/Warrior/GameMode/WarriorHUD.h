// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WarriorHUD.generated.h"

class UMainUserWidget;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY()
	UMainUserWidget* MainUserWidget;

	
	
};
