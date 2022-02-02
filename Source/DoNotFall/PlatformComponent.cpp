// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformComponent.h"

void UPlatformComponent::Destroy()
{
}

bool UPlatformComponent::IsOverLapping()
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn))
	{

	}
	return true;
}

