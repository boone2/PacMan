// Fill out your copyright notice in the Description page of Project Settings.

#include "PacManCharacter.h"
#include "Kismet/GamePlayStatics.h"


// Sets default values
APacManCharacter::APacManCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacManCharacter::BeginPlay()
{
    Super::BeginPlay();


}

// Called every frame
void APacManCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    GameMode = Cast<APacManGameModeBase>(UGameplayStatics::GetGameMode(this));
}

// Called to bind functionality to input
void APacManCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveX", this, &APacManCharacter::MoveX);
    PlayerInputComponent->BindAxis("MoveY", this, &APacManCharacter::MoveY);
    PlayerInputComponent->BindAction("NewGame", IE_Pressed, this, &APacManCharacter::NewGame);
    PlayerInputComponent->BindAction("ReStart", IE_Pressed, this, &APacManCharacter::ReStart);
    PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &APacManCharacter::Pause);
}

void APacManCharacter::MoveX(float AxisValue)
{
    Velocity.X = AxisValue;
    AddMovementInput(Velocity);
}

void APacManCharacter::MoveY(float AxisValue)
{
    Velocity.Y = AxisValue;
    AddMovementInput(Velocity);
}

void APacManCharacter::ReStart()
{
    GetWorld()->GetFirstPlayerController()->ConsoleCommand(TEXT("ReStartLevel"));
}

void APacManCharacter::NewGame()
{
    if (GameMode->GetCurrentState() == EGameState::Menu)
    {
        GameMode->SetCurrentState(EGameState::Playing);
    }
}

void APacManCharacter::Pause()
{
    if (GameMode->GetCurrentState() == EGameState::Playing)
    {
        GameMode->SetCurrentState(EGameState::Pause);
    }
    else if (GameMode->GetCurrentState() == EGameState::Pause)
    {
        GameMode->SetCurrentState(EGameState::Playing);
    }
}

