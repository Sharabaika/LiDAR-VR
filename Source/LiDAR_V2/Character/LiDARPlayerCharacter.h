#pragma once
#include "CoreMinimal.h"
#include "LiDARMotionControllerComponent.h"
#include "PlayerMovementComponent.h"
#include "VRCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "LiDARPlayerCharacter.generated.h"

UCLASS()
class ALiDARPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Subobjects //
	// ========== //
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRCamera* VRCamera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ULiDARMotionControllerComponent* LeftMotionController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ULiDARMotionControllerComponent* RightMotionController;

	
public:	
	// Lifecycle //
	// ========= //
	ALiDARPlayerCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	

	// Methods //
	// ======= //
	UFUNCTION(BlueprintCallable)
	ULiDARMotionControllerComponent* GetMotionController(ELeftRight WhichHand) const;
	
	UPlayerMovementComponent* GetPlayerMovementComponent();
	APlayerController* GetPlayerController();
	
};
