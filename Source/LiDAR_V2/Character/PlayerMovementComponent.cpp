#include "PlayerMovementComponent.h"
#include "GameFramework/Character.h"
#include "LiDAR_V2/Generic/Names.h"


UPlayerMovementComponent::UPlayerMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

void UPlayerMovementComponent::SetDependencies(USceneComponent* InCameraComponent)
{
	CameraComponent = InCameraComponent;
}

void UPlayerMovementComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(InputNames::Strafe, this, &ThisClass::OnStrafe);
	PlayerInputComponent->BindAxis(InputNames::MoveFrontBack, this, &ThisClass::OnMoveFrontBack);
	PlayerInputComponent->BindAxis(InputNames::Turn, this, &ThisClass::OnTurn);
}

void UPlayerMovementComponent::OnStrafe(float Amount)
{
	AddInputVector(CameraComponent->GetRightVector() * Amount);
}

void UPlayerMovementComponent::OnMoveFrontBack(float Amount)
{
	AddInputVector(CameraComponent->GetForwardVector() * Amount);
}

void UPlayerMovementComponent::OnTurn(float Amount)
{
	AddYaw(Amount);
}

void UPlayerMovementComponent::AddYaw(float Amount)
{
	auto* Controller{ Cast<APlayerController>(CharacterOwner->GetController()) };
	if (!Controller)
	{
		return;
	}
	Controller->RotationInput.Yaw += Amount;
}
