// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasArmas.h"
#include "FMCapsulaEnergia.h"
#include "FMCapsulaArmamento.h"
#include "FMCapsulaVida.h"

AFMCapsula* AGeneradorCapsulasArmas::FabricarCapsula(FString NombreTipoCapsula)
{
    float UbicacionAparicionCapsulax = FMath::RandRange(-1000, 1000);
    float UbicacionAparicionCapsulay = FMath::RandRange(-1000, 1000);
	if (NombreTipoCapsula.Equals("Arma1")) {
		return GetWorld()->SpawnActor<AFMCapsulaArmamento>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 100.0f), FRotator::ZeroRotator);
	}
    else if (NombreTipoCapsula.Equals("Energia1")) {
        return GetWorld()->SpawnActor<AFMCapsulaEnergia>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 100.0f), FRotator::ZeroRotator);
    }
     else if (NombreTipoCapsula.Equals("Vida1")) {
        return GetWorld()->SpawnActor<AFMCapsulaVida>(FVector(UbicacionAparicionCapsulax, UbicacionAparicionCapsulay, 100.0f), FRotator::ZeroRotator);
    }

    return nullptr;
}