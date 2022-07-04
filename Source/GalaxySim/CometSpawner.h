// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectSpawner.h"
#include "CometSpawner.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYSIM_API ACometSpawner : public AObjectSpawner
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* ImpactNiagaraTemplate;
};
