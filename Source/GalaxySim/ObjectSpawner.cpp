// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectSpawner.h"

// Sets default values
AObjectSpawner::AObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Spawner Constructor"));
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	if (NiagaraTemplate != nullptr) {
		FRotator Rotation(0, 0, 0);
		GalaxySpawn = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraTemplate, GetActorLocation(), Rotation);
		//GalaxySpawn->AdvanceSimulationByTime(startTime, 0.01);
		//GalaxySpawn->SetPaused(true);
		UE_LOG(LogTemp, Warning, TEXT("Spawned Object"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Niagara Template"));
	}
}

// Called every frame
void AObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObjectSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GalaxySpawn->DestroyInstance();
	GalaxySpawn = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("Destroyed Object"));
}
