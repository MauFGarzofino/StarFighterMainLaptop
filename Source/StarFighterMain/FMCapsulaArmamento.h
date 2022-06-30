// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FMCapsula.h"
#include "FMCapsulaArmamento.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API AFMCapsulaArmamento : public AFMCapsula
{
	GENERATED_BODY()
public:
	AFMCapsulaArmamento();

	UFUNCTION()
		virtual void NotifyHit(UPrimitiveComponent* MyComp,
			AActor* Other, class UPrimitiveComponent* OtherComp,
			bool bSelfMoved, FVector HitLocation, FVector HitNormal,
			FVector NormalImpulse, const FHitResult& Hit) override;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Generar() override;
};
