﻿#include "LiDARPlayerCharacter.h"
#include "LiDAR_V2/Generic/Macros.h"


ALiDARPlayerCharacter::ALiDARPlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super{ ObjectInitializer
		.SetDefaultSubobjectClass<UPlayerMovementComponent>(CharacterMovementComponentName)
		}
	, INIT_COMPONENT(UVRCamera, VRCamera)
	, INIT_COMPONENT(ULiDARMotionControllerComponent, LeftMotionController)
	, INIT_COMPONENT(ULiDARMotionControllerComponent, RightMotionController)
	, INIT_COMPONENT(UPlayerInteractionComponent, PlayerInteractionComponent)
{
	VRCamera->SetupAttachment(RootComponent);

	LeftMotionController->SetupAttachment(RootComponent);
	RightMotionController->SetupAttachment(RootComponent);
	
	GetPlayerMovementComponent()->SetDependencies(VRCamera);
}

void ALiDARPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->Priority = 0;
	
	GetPlayerMovementComponent()->SetupPlayerInputComponent(PlayerInputComponent);

	VRCamera->SetupInputComponent(PlayerInputComponent);
	
	APlayerController* PlayerController = GetPlayerController();
	LeftMotionController->SetupPlayerInputComponent(PlayerController, PlayerInputComponent, ELeftRight::Left);
	RightMotionController->SetupPlayerInputComponent(PlayerController, PlayerInputComponent, ELeftRight::Right);

	PlayerInteractionComponent->SetupPlayerInputComponent(PlayerInputComponent);
}

ULiDARMotionControllerComponent* ALiDARPlayerCharacter::GetMotionController(ELeftRight WhichHand) const
{
	ensure(WhichHand!=ELeftRight::Invalid);
	return WhichHand == ELeftRight::Left ? LeftMotionController : RightMotionController;
}

UPlayerMovementComponent* ALiDARPlayerCharacter::GetPlayerMovementComponent()
{
	return Cast<UPlayerMovementComponent>(GetCharacterMovement());
}

APlayerController* ALiDARPlayerCharacter::GetPlayerController()
{
	return Cast<APlayerController>(Controller);
}
