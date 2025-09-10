// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/GameMode/WarriorHUD.h"

#include "Warrior/UMG/Main/MainUserWidget.h"


void AWarriorHUD::BeginPlay()
{
	Super::BeginPlay();

	TSubclassOf<UMainUserWidget> MainUserWidgetClass = LoadClass<UMainUserWidget>(nullptr,
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/A_Game/UMG/Main/WBP_MainUserWidget.WBP_MainUserWidget_C'"));
	if (MainUserWidgetClass != nullptr)
	{
		MainUserWidget = CreateWidget<UMainUserWidget>(GetOwningPlayerController(),MainUserWidgetClass);
	}
	
	
}
