// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"

// Sets default values
AMuro::AMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroMeshAsset(TEXT("StaticMesh'/Engine/VREditor/TransformGizmo/PlaneTranslationHandle.PlaneTranslationHandle'"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	MuroMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	MuroMesh->SetStaticMesh(MuroMeshAsset.Object);
	MuroMesh->BodyInstance.SetCollisionProfileName("Muro");
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

