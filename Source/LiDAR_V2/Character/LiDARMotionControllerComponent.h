#pragma once
#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "LiDAR_V2/Generic/Generic.h"
#include "LiDARMotionControllerComponent.generated.h"

UCLASS()
class ULiDARMotionControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()
	
	// Dependencies //
	// ============ //	
	UPROPERTY(Transient)
	APlayerController* PlayerController;


	// Subobjects //
	// ========== //
	UPROPERTY(Transient)
	UInputComponent* FakeVrInputComponent;


	// State //
	// ===== //
	UPROPERTY()
	ELeftRight WhichHand;
	
	
public:
	// Lifecycle //
	// ========= //
	ULiDARMotionControllerComponent(const FObjectInitializer& ObjectInitializer);
	void SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand);


private:
	// Input //
	// ===== //
	void OnGripPressed();
	void OnGripReleased();

	void OnTriggerPressed();
	void OnTriggerReleased();
	
	
	// Fake Input //
	// ---------- //
	void EnableFakeInput();
	void DisableFakeInput();
	
	void OnFakeX(float Value);
	void OnFakeY(float Value);
	void OnFakeZ(float Value);


	// Subroutines //
	// =========== //
	bool ShouldRotateFakeInput();
};
