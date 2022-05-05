// Copyright Epic Games, Inc. All Rights Reserved.


#include "DoNotFallGameModeBase.h"

//void ADoNotFallGameModeBase::StartPlay()
//{
//	Super::StartPlay();
//
//	check(GEngine != nullptr);
//
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is DoNotFallGameModeBase!"));
//}


ADoNotFallGameModeBase::ADoNotFallGameModeBase()
{
	CurrentLevelIndex = 0;
}

void ADoNotFallGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	Controller = GetWorld()->GetFirstPlayerController();

	CheckLevel();
}

void ADoNotFallGameModeBase::EndGame()
{
	FString LevelString = GetWorld()->GetMapName();
	FName LevelToLoad = FName(*LevelString);

	UGameplayStatics::OpenLevel(this, LevelToLoad, true);
}

void ADoNotFallGameModeBase::LevelComplete()
{
	if (DefaultLevelCompleteWidget)
	{
		LevelCompleteWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultLevelCompleteWidget);
		LevelCompleteWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Completion Widget not shown"));
	}
}


void ADoNotFallGameModeBase::CheckLevel()
{
	FString CurrentLevelName = GetWorld()->GetMapName();

	Levels.Find(CurrentLevelName, CurrentLevelIndex);

	if (CurrentLevelIndex < Levels.Num() - 1)
	{
		NextLevel = Levels[CurrentLevelIndex + 1];
	}
	else
	{
		NextLevel = "End";
	}
}

void ADoNotFallGameModeBase::LoadNextLevel()
{
	if (Levels.Contains(NextLevel))
	{
		FName LevelToLoad = FName(*NextLevel);
		UGameplayStatics::OpenLevel(this, LevelToLoad, true);
	}

}