// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacManGameModeBase.generated.h"

enum class EGameState : short
{
    Menu,
    Playing,
    Pause,
    Win,
    GameOver
};

/**
 * 
 */
UCLASS()
class PACMAN_API APacManGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    EGameState GetCurrentState() const;
    void SetCurrentState(EGameState State);
	
private:
    EGameState CurrentState;
};

FORCEINLINE EGameState APacManGameModeBase::GetCurrentState() const
{
    return CurrentState;
}

FORCEINLINE void APacManGameModeBase::SetCurrentState(EGameState State)
{
    CurrentState = State;
}
