#include "VRCamera.h"

#include "LiDAR_V2/Generic/Names.h"


UVRCamera::UVRCamera(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

void UVRCamera::SetupInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis(InputNames::FakeVRCamera_Pitch, this, &ThisClass::OnFakeCameraPitch);
}

void UVRCamera::OnFakeCameraPitch(float Value)
{
	AddLocalRotation(FRotator{Value, 0, 0});
}
