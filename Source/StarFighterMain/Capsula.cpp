// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "Muro.h"
#include "Math/UnrealMathUtility.h"

ACapsula::ACapsula():Super()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_01.SM_Cube_01'"));
    if (MeshAsset.Object != nullptr)
    {
        GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
        GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
    }
    GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
    SetActorEnableCollision(true);
}

float ACapsula::RandRange(float InMin, float InMax)
{
	return 0.0f;
}

void ACapsula::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    AMuro* InventoryItem = Cast<AMuro>(Other);
    if (InventoryItem != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("CapsulaDestruida"));
        this->Destroy();
    }
}

void ACapsula::BeginPlay()
{
    Super::BeginPlay();
}

void ACapsula::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    srand(time(NULL));
    random = rand() % ((20) - (-20));
    float MoveSpeedCube = rand() % ((10) - (200));
    /*float MoveSpeedCube = RandRange(10,200);*/
    const FVector MoveDirection = FVector(-100.0f, random, 0.0f).GetClampedToMaxSize(1.0f);
    const FVector Movement = MoveDirection * MoveSpeedCube * DeltaTime;

    if (Movement.SizeSquared() > 0.0f)
    {
        const FRotator NewRotation = Movement.Rotation();
        FHitResult Hit(1.f);
        RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
    }
}

void ACapsula::PickUp()
{
    SetActorTickEnabled(false);
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
}

void ACapsula::PutDown(FTransform TargetLocation)
{
    SetActorTickEnabled(true);
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);
    SetActorLocation(TargetLocation.GetLocation());
}


