#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "VRCamera.generated.h"

UCLASS()
class UVRCamera : public UCameraComponent
{
	GENERATED_BODY()

public:
	// Lifecycle //
	// ========= //
	UVRCamera(const FObjectInitializer& ObjectInitializer);
	void SetupInputComponent(UInputComponent* InputComponent);


protected:
	// Input //
	// ===== //
	void OnFakeCameraPitch(float Value);
};
