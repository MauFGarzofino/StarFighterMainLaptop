// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FMCapsula.h"
#include "FMCapsulaEnergia.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API AFMCapsulaEnergia : public AFMCapsula
{
	GENERATED_BODY()
public:
	AFMCapsulaEnergia();
protected:
	virtual void BeginPlay() override;

public: 
	virtual void Generar() override;
	UFUNCTION()
		virtual void NotifyHit(UPrimitiveComponent* MyComp,
			AActor* Other, class UPrimitiveComponent* OtherComp,
			bool bSelfMoved, FVector HitLocation, FVector HitNormal,
			FVector NormalImpulse, const FHitResult& Hit) override;
};
