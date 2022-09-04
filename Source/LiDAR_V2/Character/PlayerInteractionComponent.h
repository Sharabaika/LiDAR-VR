#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LiDAR_V2/Items/InventoryItemBase.h"
#include "PlayerInteractionComponent.generated.h"

UCLASS()
class UPlayerInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Lifecycle //
	// ========= //
	UPlayerInteractionComponent(const FObjectInitializer& ObjectInitializer);
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	
	// Methods //
	// ======= //
	void EquipItem(AInventoryItemBase* InItem);


protected:
	// Input //
	// ===== //
	void StartGripLeft();
	void EndGripLeft();
	void StartTriggerLeft();
	void EndTriggerLeft();

	void StartGripRight();
	void EndGripRight();
	void StartTriggerRight();
	void EndTriggerRight();
};
