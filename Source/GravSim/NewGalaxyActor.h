// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Niagaracomponent.h"
#include "NewGalaxyActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRAVSIM_API UNewGalaxyActor : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* NiagaraTemplate;
public:	
	// Sets default values for this component's properties
	UNewGalaxyActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
