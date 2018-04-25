// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Enemy.h"
#include "TimerManager.h"

void AEnemyController::Possess(APawn* InPawn)
{
    Super::Possess(InPawn);
    Bot = Cast<AEnemy>(InPawn);
    HomeLocation = Bot->GetActorLocation();
    SearchNewPoint();
}

void AEnemyController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    if (!Bot->IsDead())
        SearchNewPoint();
}

void AEnemyController::GoHome()
{
    MoveToLocation(HomeLocation);
    GetWorldTimerManager().SetTimer(DeadTimer, this, &AEnemyController::ReArm, 5);
}

void AEnemyController::ReArm()
{
    GetWorldTimerManager().ClearTimer(DeadTimer);
    Bot->ReArm();
}

void AEnemyController::SearchNewPoint()
{
    UNavigationSystem* NavMesh = UNavigationSystem::GetCurrent(this);
    if (NavMesh)
    {
        const float SearchRadius = 10000;
        FNavLocation RandomPoint;
        const bool bIsFound = NavMesh->GetRandomReachablePointInRadius(Bot->GetActorLocation(), SearchRadius, RandomPoint);
        if (bIsFound)
        {
            MoveToLocation(RandomPoint);
        }
    }
}
