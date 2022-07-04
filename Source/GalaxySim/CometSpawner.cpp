// Fill out your copyright notice in the Description page of Project Settings.


#include "CometSpawner.h"

// Called every frame
void ACometSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector AObjLocation = GetActorLocation();
	SetActorLocation(FVector(AObjLocation.X+1000, AObjLocation.Y + 1000, AObjLocation.Z-100));
	GalaxySpawn->SetWorldLocation(GetActorLocation());
	

}
