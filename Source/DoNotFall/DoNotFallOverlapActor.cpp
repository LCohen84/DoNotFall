// Fill out your copyright notice in the Description page of Project Settings.


#include "DoNotFallOverlapActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ADoNotFallOverlapActor::ADoNotFallOverlapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector{ 40.0 });
	MyBoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = MyBoxComponent;

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADoNotFallOverlapActor::OnOverLapBegin);

	
}

// Called when the game starts or when spawned
void ADoNotFallOverlapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoNotFallOverlapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ADoNotFallOverlapActor::OnOverLapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
	{
		Destroy();
	}