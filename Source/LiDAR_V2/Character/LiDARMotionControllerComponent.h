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
	UInputComponent* FakeVRControllerInputComponent;


	// State //
	// ===== //
	UPROPERTY()
	ELeftRight WhichHand;

	UPROPERTY()
	float GripValue;
	
	UPROPERTY()
	float TriggerValue;

	
public:
	// Accessors //
	// ========= //
	UFUNCTION(BlueprintCallable)
	float GetGripValue() const { return GripValue; }

	UFUNCTION(BlueprintCallable)
	float GetTriggerValue() const { return TriggerValue;}
	
	
	// Lifecycle //
	// ========= //
	ULiDARMotionControllerComponent(const FObjectInitializer& ObjectInitializer);
	void SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand);


private:
	// Input //
	// ===== //
	void OnGrip(float Value);
	void OnTrigger(float Value);
	
	
	// Fake Input //
	// ---------- //
	void OnFakeTriggerPressed();
	void OnFakeTriggerReleased();
	
	void OnFakeGripPressed();
	void OnFakeGripReleased();
	
	void EnableFakeControllerInput();
	void DisableFakeControllerInput();
	
	void OnFakeX(float Value);
	void OnFakeY(float Value);
	void OnFakeZ(float Value);


	// Subroutines //
	// =========== //
	bool IsSuitableFakeInputHand() const;
	bool ShouldRotateFakeInput() const;
};
