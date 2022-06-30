// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FMCapsula.h"
#include "FMCapsulaVida.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API AFMCapsulaVida : public AFMCapsula
{
	GENERATED_BODY()
public:
	AFMCapsulaVida();
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
