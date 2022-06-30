// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaAliada.h"
#include "Projectile.h"

ANaveAereaAliada::ANaveAereaAliada()
{
	MoveSpeed = 400.0f;

	// Weapon
	GunOffset = FVector(90.0f, 0.0f, 0.f);
	FireRate = 10.0f;
	bCanFire = false;
	FireForwardValue = 1.0f;
	FireRightValue = 0.0f;
}

void ANaveAereaAliada::Fire()
{
	bCanFire = true;
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
	FireShot(FireDirection);
}

void ANaveAereaAliada::FireShot(FVector FireDirection)
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
			GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("1")));
		}
		//bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaAliada::ShotTimerExpired, FireRate);
		bCanFire = false;
	}
}

void ANaveAereaAliada::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveAereaAliada::BeginPlay()
{
	Super::BeginPlay();

	TotalTime = 0.0f;

	TimeSinceLastShot = 0.0f;

	fDestroyTimer = 1.0f;

	ThisWorld = GetWorld();

	RandomStart = FMath::Rand();
}

void ANaveAereaAliada::Tick(float DeltaTime)
{
	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	Current_Location.X += FMath::Sin(TotalTime + RandomStart);

	this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	//handle shooting

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;

	if (TimeSinceLastShot >= 1.0f && !bHit) {
		const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
		const FRotator FireRotation = FireDirection.Rotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		if (fBurstDelay >= 0.01f) {
			FActorSpawnParameters Params = {};
			Params.Owner = this;
			GetWorld()->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
			fBurstDelay = 0.0f;
		}
		TimeSinceLastShot = 0.0f;
		fBurstDelay += DeltaTime;
	}
}

void ANaveAereaAliada::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
}
