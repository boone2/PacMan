// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Enemy.h"


void AEnemyController::Possess(APawn* InPawn)
{
    Super::Possess(InPawn);
    Bot = Cast<AEnemy>(InPawn);
}

void AEnemyController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
}

void AEnemyController::SearchNewPoint()
{
    UNavigationSystem* NavMesh = UNavigationSystem::GetCurrent(this);
    if (NavMesh)
    {
        const float SearchRadius = 1000;
        FNavLocation RandomPoint;
        bool bIsFound = NavMesh->GetRandomReachablePointInRadius(Bot->GetActorLocation(), SearchRadius, RandomPoint);
        if (bIsFound)
        {
            MoveToLocation(RandomPoint);
        }
    }
}
