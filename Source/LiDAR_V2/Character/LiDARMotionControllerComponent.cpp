#include "LiDARMotionControllerComponent.h"

#include "HeadMountedDisplayFunctionLibrary.h"
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
	
	// Fake input
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Pressed, this, &ThisClass::EnableFakeControllerInput);
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Released, this, &ThisClass::DisableFakeControllerInput);
	
	const static FName GripNames[]{InputNames::GripLeft, InputNames::GripRight };
	const FName GripName{ GripNames[WhichHandInt] };
	InputComponent->BindAction(GripName, IE_Pressed, this, &ThisClass::OnFakeGripPressed)
		.bConsumeInput = false;
	InputComponent->BindAction(GripName, IE_Released, this, &ThisClass::OnFakeGripReleased)
		.bConsumeInput = false;

	const static FName TriggerNames[]{InputNames::TriggerLeft, InputNames::TriggerRight };
	const FName TriggerName{ TriggerNames[WhichHandInt] };
	InputComponent->BindAction(TriggerName, IE_Pressed, this, &ThisClass::OnFakeTriggerPressed)
		.bConsumeInput = false;
	InputComponent->BindAction(TriggerName, IE_Released, this, &ThisClass::OnFakeTriggerReleased)
		.bConsumeInput = false;
	
	FakeVRControllerInputComponent = NewObject<UInputComponent>(
			PlayerController,
			FName{ TEXT("Motion Controller Keyboard Mouse Rotation Input"), WhichHandInt},
			RF_Transient);
	FakeVRControllerInputComponent->Priority = 1;
	
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_X, this, &ThisClass::OnFakeX);
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_Y, this, &ThisClass::OnFakeY);
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_Z, this, &ThisClass::OnFakeZ);

	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		// Native
		const static FName GripAxisNames[]{InputNames::GripLeftAxis, InputNames::GripRightAxis };
		InputComponent->BindAxis(GripAxisNames[WhichHandInt], this, &ThisClass::OnGrip);
		
		const static FName TriggerAxisNames[]{InputNames::TriggerLeftAxis, InputNames::TriggerRightAxis };
		InputComponent->BindAxis(TriggerAxisNames[WhichHandInt], this, &ThisClass::OnTrigger);
	}
}

void ULiDARMotionControllerComponent::OnGrip(float Value)
{
	GripValue = Value;
}

void ULiDARMotionControllerComponent::OnTrigger(float Value)
{
	TriggerValue = Value;
}

void ULiDARMotionControllerComponent::OnFakeTriggerPressed()
{
	if (IsSuitableFakeInputHand())
	{
		TriggerValue = 1.0f;
	}
}

void ULiDARMotionControllerComponent::OnFakeTriggerReleased()
{
	TriggerValue = 0.0f;
}

void ULiDARMotionControllerComponent::OnFakeGripPressed()
{
	if (IsSuitableFakeInputHand())
	{
		GripValue = 1.0f;
	}
}

void ULiDARMotionControllerComponent::OnFakeGripReleased()
{
	GripValue = 0.0f;
}

void ULiDARMotionControllerComponent::EnableFakeControllerInput()
{
	if (IsSuitableFakeInputHand())
	{
		PlayerController->PushInputComponent(FakeVRControllerInputComponent);
	}
}

void ULiDARMotionControllerComponent::DisableFakeControllerInput()
{
	
	PlayerController->PopInputComponent(FakeVRControllerInputComponent);
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

bool ULiDARMotionControllerComponent::IsSuitableFakeInputHand() const
{
	return WhichHand == ELeftRight::Right != PlayerController->PlayerInput->IsAltPressed();
}

bool ULiDARMotionControllerComponent::ShouldRotateFakeInput() const
{
	return PlayerController->PlayerInput->IsPressed(EKeys::ThumbMouseButton2);
}
