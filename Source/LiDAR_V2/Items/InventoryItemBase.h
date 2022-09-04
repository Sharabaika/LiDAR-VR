#pragma once
#include "CoreMinimal.h"
#include "InventoryItemInteractionComponent.h"
#include "GameFramework/Actor.h"
#include "InventoryItemBase.generated.h"

UCLASS()
class AInventoryItemBase : public AActor
{
	GENERATED_BODY()

	// Subobjects //
	// ========== //
	UPROPERTY()
	UInventoryItemInteractionComponent* MainInteractionComponent;

	
public:
	// Lifecycle //
	// ========= //
	AInventoryItemBase(const FObjectInitializer& ObjectInitializer);


	// Methods //
	// ======= //
	virtual UInventoryItemInteractionComponent* GetInteractionComponent() const;
	
};
