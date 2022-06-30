// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfacePrueba.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfacePrueba : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTERMAIN_API IInterfacePrueba
{
	GENERATED_BODY()
		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//The pure virtual functions of the LodgingBuilder
	virtual void BuildAntiAir_Turret() = 0;
	// man portable air defense system)
	virtual void BuildMPADS() = 0;
    // sistema de misiles tierra aire 
	virtual void BuildMIM_104_Patriot() = 0;
	//Norwegian Advanced Surface to Air Missile System
	virtual void BuildNASAMS() = 0;
	virtual class AAirDefenseSystem* GetLodging() = 0;

public:
};
