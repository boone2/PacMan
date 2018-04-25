// Fill out your copyright notice in the Description page of Project Settings.

#include "PacManGameModeBase.h"
#include "EngineUtils.h"
#include "Enemy.h"


void APacManGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentState(EGameState::Menu);
    for (TActorIterator<AEnemy> It(GetWorld()); It; ++It)
    {
        auto Enemy = Cast<AEnemy>(*It);
        if (Enemy)
        {
            Enemies.Add(Enemy);
        }
    }
}

void APacManGameModeBase::SetEnemyVulnerable()
{
    for (auto Enemy : Enemies)
    {
        Enemy->SetVulnerable();
    }
}

void APacManGameModeBase::SetCurrentState(EGameState State)
{
    CurrentState = State;
    switch (State)
    {
    case EGameState::Menu: break;
    case EGameState::Playing:
        for (auto Enemy : Enemies)
        {
            Enemy->SetMove(true);
        }
        break;
    case EGameState::Pause:
        for (auto Enemy : Enemies)
        {
            Enemy->SetMove(false);
        }
        break;
    case EGameState::Win:
        for (auto Enemy : Enemies)
        {
            Enemy->Destroyed();
        }
        break;
    case EGameState::GameOver:
        break;
    }
}
