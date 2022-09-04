#include "PlayerInteractionComponent.h"


UPlayerInteractionComponent::UPlayerInteractionComponent(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

void UPlayerInteractionComponent::EquipItem(AInventoryItemBase* InItem)
{
	UInventoryItemInteractionComponent* InteractionComponent{ InItem->GetInteractionComponent() };

	// InItem->AttachToComponent();
}
