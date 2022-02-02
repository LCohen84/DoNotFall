// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DoNotFallGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DONOTFALL_API ADoNotFallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
