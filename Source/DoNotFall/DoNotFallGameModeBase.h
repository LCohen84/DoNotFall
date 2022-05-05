// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "DoNotFallGameModeBase.generated.h"


UCLASS()
class DONOTFALL_API ADoNotFallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	//virtual void StartPlay() override;

public:

	ADoNotFallGameModeBase();
	void EndGame();
	void LevelComplete();
	void LoadNextLevel();

protected:

	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<UUserWidget> DefaultLevelCompleteWidget;
	UPROPERTY(EditAnywhere, Category = "Widgets")
		UUserWidget* LevelCompleteWidget;

	UPROPERTY(EditAnywhere, Category = "Widgets")
		TSubclassOf<UUserWidget> DefaultGameCompleteWidget;
	UPROPERTY(EditAnywhere, Category = "Widgets")
		UUserWidget* GameCompleteWidget;

private:

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Levels")
		TArray<FString> Levels;

	APlayerController* Controller;
	int32 CurrentLevelIndex;
	FString NextLevel;

	void CheckLevel();
};
