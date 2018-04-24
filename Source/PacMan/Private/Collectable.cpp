// Fill out your copyright notice in the Description page of Project Settings.

#include "Collectable.h"
#include "ConstructorHelpers.h"


// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    SetActorEnableCollision(true);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectableMesh"));
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    MeshComponent->AttachToComponent(CollisionComponent, FAttachmentTransformRules::KeepRelativeTransform);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("StaticMesh'/Engine/BasicShapes/Sphere'"));
    if (Sphere.Succeeded())
    {
        MeshComponent->SetStaticMesh(Sphere.Object);
    }

    MeshComponent->SetWorldScale3D(FVector(0.3, 0.3, 0.3));
    CollisionComponent->SetSphereRadius(16);

    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    SetRootComponent(CollisionComponent);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

