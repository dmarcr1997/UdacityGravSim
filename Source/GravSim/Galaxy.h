// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "Niagaracomponent.h"
#include "Galaxy.generated.h"

UCLASS()
class GRAVSIM_API AGalaxy : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* NiagaraTemplate;

	UPROPERTY(EditAnywhere)
	float startTime = 20;


public:	
	// Sets default values for this actor's properties
	AGalaxy();
	float GalaxyYaw = 0.0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason);

	UNiagaraComponent* GalaxySpawn;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
