// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Collectable.generated.h"

UCLASS()
class PACMAN_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
    bool IsSupper() const;

private:
    UPROPERTY(EditDefaultsOnly, Category = Collectable)
	UStaticMeshComponent *MeshComponent = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = Collectable)
    USphereComponent *CollisionComponent = nullptr;

    UPROPERTY(EditAnywhere, Category = Collectable)
    bool bIsSupper = false;
};

FORCEINLINE bool ACollectable::IsSupper() const
{
    return bIsSupper;
}
