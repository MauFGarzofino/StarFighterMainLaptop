// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemiga.h"
#include "Projectile.h"

ANaveAereaEnemiga::ANaveAereaEnemiga():Super()
{
	MoveSpeed = 400.0f;

	// Weapon
	GunOffset = FVector(90.0f, 0, 0.f);
	FireRate = 1.0f;
	bCanFire = false;
	FireForwardValue = 1.0f;
	FireRightValue = 0.0f;
	b = 0;
	c = 0.0f;
	Temporizador = 0;

	// EXAMEN
    vidaNave = 10;
    numNavesDestruidas = 0;
}

void ANaveAereaEnemiga::Fire()
{
	bCanFire = true;
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
	FireShot(FireDirection);

}

void ANaveAereaEnemiga::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		const FRotator FireRotation = FireDirection.Rotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
		}
		//bCanFire = false;
		bCanFire = false;
	}
}

void ANaveAereaEnemiga::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveAereaEnemiga::Contador()
{
}

void ANaveAereaEnemiga::BeginPlay()
{
	Super::BeginPlay();

	TotalTime = 0.0f;

	TimeSinceLastShot = 0.9f;

	fDestroyTimer = 1.0f;

	ThisWorld = GetWorld();

	RandomStart = FMath::Rand();

	//GEngine->AddOnScreenDebugMessage(0, 5000, FColor::Silver, FString::Printf(TEXT("Naves Destruidas: %d"), numNavesDestruidas));

}

void ANaveAereaEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	Current_Location.X += FMath::Sin(TotalTime + RandomStart);

	this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	//handle shooting

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;

	// 
	//c += DeltaTime;

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;

	//UE_LOG(LogTemp, Warning, TEXT("Valor de Time: %f"), TimeSinceLastShot)
	c += DeltaTime;
	//c += DeltaTime;


	if (TimeSinceLastShot >= 1.0f && !bHit) {
		const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
		const FRotator FireRotation = FireDirection.Rotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		if (fBurstDelay >= 0.01f) {
			FActorSpawnParameters Params = {};
			Params.Owner = this;
			GetWorld()->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
			// contator 
			//if (c < 60) {
				/*c += 1;*/
			b += 1;
			/*UE_LOG(LogTemp, Warning, TEXT("b:, %d"), b)*/
			if (Temporizador < 60){
				GEngine->AddOnScreenDebugMessage(0, 10, FColor::Silver, FString::Printf(TEXT("BalasDisparadasNaveEnemiga: %d"), b));
		    }
			//}		
				//UE_LOG(LogTemp, Warning, TEXT("C:, %f"), c)
				if (c >= 1.0f) {
					Temporizador += 1;
				if (Temporizador <= 60)
				{
						/*UE_LOG(LogTemp, Warning, TEXT("Temporizador:, %d"), Temporizador)*/
		    	}
				c = 0.0f;
			}
			fBurstDelay = 0.9f;
		}
		TimeSinceLastShot = 0.9f;
		fBurstDelay += DeltaTime;
	}

	if(vidaNave == 0) {
		numNavesDestruidas++;
		vidaNave = 10;
	}
}

void ANaveAereaEnemiga::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{ 
	AProjectile* ReducirVida = Cast<AProjectile>(Other);
	if(ReducirVida != nullptr) {
		vidaNave -= 5;
		this->Destroy();
		GEngine->AddOnScreenDebugMessage(0, 5000, FColor::Silver, FString::Printf(TEXT("Naves Destruidas: %d"), numNavesDestruidas)); 
	}
	
}

