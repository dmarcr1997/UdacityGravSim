// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "Niagaracomponent.h"
#include "ObjectSpawner.generated.h"

UCLASS()
class GALAXYSIM_API AObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* NiagaraTemplate;

	UPROPERTY(EditAnywhere)
	float startTime = 20;
	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	AObjectSpawner();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UNiagaraComponent* GalaxySpawn;

};
