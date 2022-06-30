// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Singleton.generated.h"

UCLASS()
class STARFIGHTERMAIN_API ASingleton : public AActor
{
	GENERATED_BODY()
public:
    // Sets default values for this actor's properties
    ASingleton();
private:
    //The Inventory of this Actor
    UPROPERTY()
        class ANaveNodrizaM* NNodriza;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
