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

	
	// Methods //
	// ======= //
	void EquipItem(AInventoryItemBase* InItem);
};
