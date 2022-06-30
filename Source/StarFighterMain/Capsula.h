// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Capsula.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API ACapsula : public AStaticMeshActor
{
	GENERATED_BODY()
public:
    // Sets default values for this actor's properties
    ACapsula();
    float random;
    static float RandRange(float InMin, float InMax);
private:
    //    //Permite el acceso a la parte privada //, meta = (AllowPrivateAccess = "true")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos", meta = (AllowPrivateAccess = "true"))
        FString InventoryActorName;
    UFUNCTION()
        virtual void NotifyHit(UPrimitiveComponent* MyComp,
            AActor* Other, class UPrimitiveComponent* OtherComp,
            bool bSelfMoved, FVector HitLocation, FVector HitNormal,
            FVector NormalImpulse, const FHitResult& Hit) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    virtual void PickUp();
    virtual void PutDown(FTransform TargetLocation);

    FORCEINLINE FString GetInventoryActorName() const { return InventoryActorName; }
    FORCEINLINE void SetInventoryActorName(const FString _InventoryActorName) { InventoryActorName = _InventoryActorName; }
};
