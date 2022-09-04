#include "InventoryItemBase.h"


AInventoryItemBase::AInventoryItemBase(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

UInventoryItemInteractionComponent* AInventoryItemBase::GetInteractionComponent() const
{
	return nullptr;
}
