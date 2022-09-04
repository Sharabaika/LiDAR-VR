#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemInteractionComponent.generated.h"

UCLASS()
class UInventoryItemInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Lifecycle //
	// ========= //
	UInventoryItemInteractionComponent(const FObjectInitializer& ObjectInitializer);
};
