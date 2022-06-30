// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseOfNames.h"
#include "AirDefenseSystem.generated.h"

UCLASS()
class STARFIGHTERMAIN_API AAirDefenseSystem : public AActor , public IBaseOfNames
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAirDefenseSystem();

private:

	FString AntiAir_Turret;

	FString MPADS;

	FString MIM_104_Patriot;

	FString NASAMS;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetAntiAir_Turret(FString myAntiAir_Turret);

	void SetMPADS(FString myMPADS);

	void SetMIM_104_Patriot(FString myMIM_104_Patriot);

	void SetNASAMS(FString myNASAMS);

	void AirDefenseSystemCharacteristics();

};
