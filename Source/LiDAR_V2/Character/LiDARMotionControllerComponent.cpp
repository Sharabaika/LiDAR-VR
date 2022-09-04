#include "LiDARMotionControllerComponent.h"
#include "LiDAR_V2/Generic/Names.h"

ULiDARMotionControllerComponent::ULiDARMotionControllerComponent(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

void ULiDARMotionControllerComponent::SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand)
{
	PlayerController = InPlayerController;
	WhichHand = InWhichHand;
	const int32 WhichHandInt{ static_cast<int32>(WhichHand) };
	
	InputComponent->BindAction(InputNames::GripNames[WhichHandInt], IE_Pressed, this, &ThisClass::OnGripPressed);
	InputComponent->BindAction(InputNames::GripNames[WhichHandInt], IE_Released, this, &ThisClass::OnGripReleased);

	InputComponent->BindAction(InputNames::TriggerNames[WhichHandInt], IE_Pressed, this, &ThisClass::OnTriggerPressed);
	InputComponent->BindAction(InputNames::TriggerNames[WhichHandInt], IE_Released, this, &ThisClass::OnTriggerReleased);
	
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Pressed, this, &ThisClass::EnableFakeInput);
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Released, this, &ThisClass::DisableFakeInput);
	
	FakeVrInputComponent = NewObject<UInputComponent>(
			PlayerController,
			FName{ TEXT("Motion Controller Keyboard Mouse Input"), WhichHandInt},
			RF_Transient);
	FakeVrInputComponent->Priority = 1;
	
	FakeVrInputComponent->BindAxis(InputNames::FakeVRController_X, this, &ThisClass::OnFakeX);
	FakeVrInputComponent->BindAxis(InputNames::FakeVRController_Y, this, &ThisClass::OnFakeY);
	FakeVrInputComponent->BindAxis(InputNames::FakeVRController_Z, this, &ThisClass::OnFakeZ);
}

void ULiDARMotionControllerComponent::OnGripPressed()
{
}

void ULiDARMotionControllerComponent::OnGripReleased()
{
}

void ULiDARMotionControllerComponent::OnTriggerPressed()
{
}

void ULiDARMotionControllerComponent::OnTriggerReleased()
{
}

void ULiDARMotionControllerComponent::EnableFakeInput()
{
	if (WhichHand == ELeftRight::Right != PlayerController->PlayerInput->IsAltPressed())
	{
		PlayerController->PushInputComponent(FakeVrInputComponent);
	}
}

void ULiDARMotionControllerComponent::DisableFakeInput()
{
	
	PlayerController->PopInputComponent(FakeVrInputComponent);
}

void ULiDARMotionControllerComponent::OnFakeX(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{Value, 0, 0});
	}
	else
	{
		AddLocalOffset(FVector::UnitX()*Value);
	}
}

void ULiDARMotionControllerComponent::OnFakeY(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{0, Value, 0});
	}
	else
	{
		AddLocalOffset(FVector::UnitY()*Value);
	}
}

void ULiDARMotionControllerComponent::OnFakeZ(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{0, 0, Value});
	}
	else
	{
		AddLocalOffset(FVector::UnitZ()*Value);
	}
}

bool ULiDARMotionControllerComponent::ShouldRotateFakeInput()
{
	return PlayerController->PlayerInput->IsPressed(EKeys::ThumbMouseButton);
}
