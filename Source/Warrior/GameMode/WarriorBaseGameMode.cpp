// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior/GameMode/WarriorBaseGameMode.h"

#include "WarriorBasePlayerController.h"
#include "WarriorHUD.h"

AWarriorBaseGameMode::AWarriorBaseGameMode()
{
	HUDClass = AWarriorHUD::StaticClass();

	PlayerControllerClass = AWarriorBasePlayerController::StaticClass();
}
