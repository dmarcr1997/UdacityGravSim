// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NiagaraFunctionLibrary.h"
#include "Niagaracomponent.h"
#include "GalaxyClass.generated.h"


UCLASS()
class GRAVSIM_API AGalaxyClass : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* NiagaraTemplate;


public:
	// Sets default values for this pawn's properties
	AGalaxyClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
