// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	//Set this character to call Tick() every frame,
	PrimaryActorTick.bCanEverTick = false;

	//Don't rotate when the controller rotates. Let that just affect the camera
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	//Configure character movement
	//Character moves in the direction of input
	GetCharacterMovement()->bOrientRotationToMovement = true;

	//Create a SpringArm and set up attach to RootComponent
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	//rotate the arm based on the controller
	SpringArm->bUsePawnControlRotation = true;
	//the Camera follows at this distance behind the character
	SpringArm->SocketOffset =  FVector(0, 30, 80);


	//Create a follow Camera 
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	//Let the follow camera attach to the spring arm 
	FollowCamera->SetupAttachment(SpringArm);
	//Camera does not rotate relative to arm
	FollowCamera->bUsePawnControlRotation = false;

	
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AttackCapsule->OnComponentBeginOverlap.AddDynamic(this,&APlayerCharacter::OnComponentBeginOverlap);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//普通按鍵綁定
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&APlayerCharacter::JumpStart);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Released,this,&APlayerCharacter::JumpEnd);

	PlayerInputComponent->BindAction(TEXT("Attack"),IE_Pressed,this,&APlayerCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("MoveForward/Backward"),this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight/Left"),this,&APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("TurnRight/LeftMouse"),this,&APlayerCharacter::TurnRight);
	

	
	
}

void APlayerCharacter::JumpStart()
{
	Jump();
}

void APlayerCharacter::JumpEnd()
{
	StopJumping();
}

void APlayerCharacter::Attack()
{
	ActiveAbility(0);
}

void APlayerCharacter::MoveForward(float X)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(FRotator(0.0, GetControlRotation().Yaw,0.0 )),X,false);
}

void APlayerCharacter::MoveRight(float X)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(FRotator(0.0,GetControlRotation().Yaw, 0.0 )),X,false);
}

void APlayerCharacter::TurnRight(float X)
{
	AddControllerYawInput(X);	
}

void APlayerCharacter::LookUp(float X)
{
	AddControllerPitchInput(X);
}

void APlayerCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->GetClass() != this->GetClass())
	{
		if (AWarriorBaseCharacter* BaseCharacter = Cast<AWarriorBaseCharacter>(OtherActor))
		{
			/*UGameplayEffect* MeleeDamage = LoadObject<UGameplayEffect>(nullptr,TEXT("/Script/Engine.Blueprint'/Game/A_Game/Abilities/FirstMelee/GE_Melee_Damage.GE_Melee_Damage'"));
			FGameplayEffectSpecHandle GameplayEffectSpecHandle = Ma*/
		}
	}
}


