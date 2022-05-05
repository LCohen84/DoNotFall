// Fill out your copyright notice in the Description page of Project Settings.


#include "DNF_NLComponent.h"

// Sets default values for this component's properties
UDNF_NLComponent::UDNF_NLComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UDNF_NLComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...

	DNF_Actor = GetWorld()->GetFirstPlayerController()->GetPawn();

	
}


// Called every frame
void UDNF_NLComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (MyVolume->IsOverlappingActor(DNF_Actor))
	{
		//GameMode->LoadNextLevel();
	}
	// ...
}

void UDNF_NLComponent::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}
