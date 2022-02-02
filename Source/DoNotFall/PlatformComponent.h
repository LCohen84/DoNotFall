// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerBox.h"
#include "PlatformComponent.generated.h"

class ABoxTrigger;

UCLASS()
class DONOTFALL_API UPlatformComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

	virtual void Destroy();
	virtual bool IsOverLapping();
	
	
	UPROPERTY(EditAnywhere)
	ABoxTrigger* TriggerBox;
};
