// Fill out your copyright notice in the Description page of Project Settings.

#include "PacManGameModeBase.h"
#include "EngineUtils.h"
#include "Enemy.h"


void APacManGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentState(EGameState::Playing);
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
