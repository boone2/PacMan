// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class PACMAN_API AEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AEnemy();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Components
private:
    UPROPERTY(VisibleAnywhere, Category = Body)
    UStaticMeshComponent* Body = nullptr;

    // Vulnerable Control
public:
    void SetVulnerable();
    void SetInvulnerable();

private:
    UMaterialInterface* DefaultMaterial = nullptr;
    UMaterialInterface* VulnerableMaterial = nullptr;
    FTimerHandle VulnerableTimer;

    // Liftcycle
public:
    void ReArm();

private:
    void SetMove(bool MoveIt);
    void OnKilled();
    void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                     int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // Properties
public:
    bool IsDead() const;

private:
    bool bIsVulnerable = false;
    bool bIsDead = false;
};

FORCEINLINE bool AEnemy::IsDead() const
{
    return bIsDead;
}
