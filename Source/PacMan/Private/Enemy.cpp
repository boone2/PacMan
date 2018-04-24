// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderObj(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder'"));
    if (CylinderObj.Succeeded())
    {
        Body->SetStaticMesh(CylinderObj.Object);
    }
    
    Body->SetRelativeScale3D(FVector(0.7f, 0.7f, 1));
    Body->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

    GetCapsuleComponent()->SetCapsuleRadius(40.0f, false);
    GetCapsuleComponent()->SetCapsuleHalfHeight(50.0f);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

