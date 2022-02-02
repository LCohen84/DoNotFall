// Fill out your copyright notice in the Description page of Project Settings.


#include "DoNotFallCharacter.h"
#include "Engine/TriggerBox.h"


// Sets default values
ADoNotFallCharacter::ADoNotFallCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoNotFallCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("We are using DoNotFallCharacter"));
}

// Called every frame
void ADoNotFallCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoNotFallCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADoNotFallCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADoNotFallCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &ADoNotFallCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ADoNotFallCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ADoNotFallCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ADoNotFallCharacter::StopJump);
}

void ADoNotFallCharacter::IsOverLapping()
{
	
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("You are overlapping"));
		UE_LOG(LogTemp, Log, TEXT("You are Overlapping!"));
		GetOwner()->Destroy(true);
	}
}

void ADoNotFallCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ADoNotFallCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ADoNotFallCharacter::StartJump()
{
	bPressedJump = true;
}

void ADoNotFallCharacter::StopJump()
{
	bPressedJump = false;
}