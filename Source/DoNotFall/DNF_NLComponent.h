// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "DoNotFallGameModeBase.h"
#include "DNF_NLComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONOTFALL_API UDNF_NLComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDNF_NLComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UPROPERTY
	UPROPERTY(EditAnywhere)
		class ATriggerVolume* MyVolume;
	UPROPERTY(EditAnyWhere)
		AActor* DNF_Actor;
		
	//UFUNCTION
	UFUNCTION()
		void OnOverLapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	class ADoNotFallGameModeBase * GameMode;
};
