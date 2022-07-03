// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Galaxy.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "CharacterPawn.generated.h"

UCLASS()
class GRAVSIM_API ACharacterPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Input functions
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void Look_XAxis(float AxisValue);
	void Look_YAxis(float AxisValue);
	void SpawnGalaxy();
	void DestroyGalaxy();
	AGalaxy* CurrectGalaxy = nullptr;

	//Input variables
	FVector CurrentVelocity;
	FVector TurnInput;
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;

	
};
