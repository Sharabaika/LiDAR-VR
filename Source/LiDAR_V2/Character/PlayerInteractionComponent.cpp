#include "PlayerInteractionComponent.h"
#include "LiDAR_V2/Generic/Names.h"


UPlayerInteractionComponent::UPlayerInteractionComponent(const FObjectInitializer& ObjectInitializer)
	: Super{ObjectInitializer}
{
}

void UPlayerInteractionComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(InputNames::GripLeft, IE_Pressed, this, &ThisClass::StartGripLeft);
	PlayerInputComponent->BindAction(InputNames::GripLeft, IE_Released, this, &ThisClass::EndGripLeft);

	PlayerInputComponent->BindAction(InputNames::TriggerLeft, IE_Pressed, this, &ThisClass::StartTriggerLeft);
	PlayerInputComponent->BindAction(InputNames::TriggerLeft, IE_Released, this, &ThisClass::EndTriggerLeft);

	PlayerInputComponent->BindAction(InputNames::GripRight, IE_Pressed, this, &ThisClass::StartGripRight);
	PlayerInputComponent->BindAction(InputNames::GripRight, IE_Released, this, &ThisClass::EndGripRight);

	PlayerInputComponent->BindAction(InputNames::TriggerRight, IE_Pressed, this, &ThisClass::StartTriggerRight);
	PlayerInputComponent->BindAction(InputNames::TriggerRight, IE_Released, this, &ThisClass::EndTriggerRight);
}

void UPlayerInteractionComponent::EquipItem(AInventoryItemBase* InItem)
{
	UInventoryItemInteractionComponent* InteractionComponent{ InItem->GetInteractionComponent() };
}

void UPlayerInteractionComponent::StartGripLeft()
{
}

void UPlayerInteractionComponent::EndGripLeft()
{
}

void UPlayerInteractionComponent::StartTriggerLeft()
{
}

void UPlayerInteractionComponent::EndTriggerLeft()
{
}

void UPlayerInteractionComponent::StartGripRight()
{
}

void UPlayerInteractionComponent::EndGripRight()
{
}

void UPlayerInteractionComponent::StartTriggerRight()
{
}

void UPlayerInteractionComponent::EndTriggerRight()
{
}
