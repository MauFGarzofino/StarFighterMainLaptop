// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BaseOfNames.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBaseOfNames : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTERMAIN_API IBaseOfNames
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//The pure virtual functions of the FloorPlan
	virtual void SetAntiAir_Turret(FString AntiAir_Turret) = 0;
	virtual void SetMPADS(FString MPADS) = 0;
	virtual void SetMIM_104_Patriot(FString MIM_104_Patriot) = 0;
	virtual void SetNASAMS(FString NASAMS) = 0;
};
