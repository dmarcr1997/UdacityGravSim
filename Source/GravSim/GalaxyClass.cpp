// Fill out your copyright notice in the Description page of Project Settings.


#include "GalaxyClass.h"

// Sets default values
AGalaxyClass::AGalaxyClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	AActor* Parent = GetOwner();
	FVector Location = Parent->GetActorLocation();
	FRotator Rotation(0,0,0);
	UNiagaraComponent* Spawn = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraTemplate, Location, Rotation);
	*/
}

// Called when the game starts or when spawned
void AGalaxyClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGalaxyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGalaxyClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

