// Fill out your copyright notice in the Description page of Project Settings.

#include "PacManGameModeBase.h"




void APacManGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentState(EGameState::Playing);
}
