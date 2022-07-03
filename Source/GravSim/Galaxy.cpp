// Fill out your copyright notice in the Description page of Project Settings.


#include "Galaxy.h"

// Sets default values
AGalaxy::AGalaxy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGalaxy::BeginPlay()
{
	Super::BeginPlay();
	FRotator Rotation(0, 0, 0);
	GalaxySpawn = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraTemplate, GetActorLocation(), Rotation);
	GalaxySpawn->AdvanceSimulationByTime(startTime, 0.01);
	GalaxySpawn->SetPaused(true);
}


// Called every frame
void AGalaxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AGalaxy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{	
	GalaxySpawn->DestroyInstance();
	GalaxySpawn = nullptr;
}

