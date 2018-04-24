// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PacManGameModeBase.h"
#include "PacManCharacter.generated.h"

UCLASS()
class PACMAN_API APacManCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    APacManCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // 角色移动
private:
    void MoveX(float AxisValue);
    void MoveY(float AxisValue);
    FVector Velocity;

    // 流程控制
public:
    void OnKilled();
private:
    void ReStart();
    void NewGame();
    void Pause();

    APacManGameModeBase* GameMode;

    // 碰撞
private:
    UFUNCTION()
    void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                     int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // 角色属性
private:
    int CollectablesNumToEat;
    int HealthPoint;
    FVector StartPoint;
};
