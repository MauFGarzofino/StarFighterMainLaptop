// Fill out your copyright notice in the Description page of Project Settings.


#include "Singleton.h"
#include "NaveNodrizaM.h"

// Sets default values
ASingleton::ASingleton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingleton::BeginPlay()
{
    Super::BeginPlay();
    //Create 4 Inventory
    int n = 1;
    for (int i = 0; i <= n; i++)
    {
        n += 1;
        ANaveNodrizaM* SpawnedNaveNodriza = GetWorld()->SpawnActor<ANaveNodrizaM>(ANaveNodrizaM::StaticClass());
        if (SpawnedNaveNodriza)
        {
            //If the Spawn succeeds, set the Spawned inventory to the local one and log the success string
            NNodriza = SpawnedNaveNodriza;
            GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"),*NNodriza->GetName()));
        }
    }
}

// Called every frame
void ASingleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

