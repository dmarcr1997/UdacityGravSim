// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterPawn.h"

// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup component hierarchy
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh);
	
}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		if (!CurrentVelocity.IsZero() )
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}

		if (!TurnInput.IsZero())
		{
			FRotator NewRotation = GetActorRotation();
			NewRotation.Yaw += TurnInput.X * DeltaTime;

			SetActorRotation(NewRotation);

			FRotator NewSpringArmRotation = GetActorRotation();
			NewSpringArmRotation.Pitch += TurnInput.Y * DeltaTime;
			SetActorRotation(NewSpringArmRotation);
		}
	}
}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
	InputComponent->BindAxis("MoveX", this, &ACharacterPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &ACharacterPawn::Move_YAxis);
	InputComponent->BindAxis("TurnX", this, &ACharacterPawn::Look_XAxis);
	InputComponent->BindAxis("TurnY", this, &ACharacterPawn::Look_YAxis);
	InputComponent->BindAction("SpawnG", IE_Pressed, this, &ACharacterPawn::SpawnGalaxy);
	InputComponent->BindAction("DestroyG", IE_Pressed, this, &ACharacterPawn::DestroyGalaxy);

}

void ACharacterPawn::Move_XAxis(float value)
{
	CurrentVelocity.X = FMath::Clamp(value, -1.0f, 1.0f) * 500.0f;
}

void ACharacterPawn::Move_YAxis(float value)
{
	CurrentVelocity.Y = FMath::Clamp(value, -1.0f, 1.0f) * 500.0f;
}

void ACharacterPawn::Look_XAxis(float value)
{
	TurnInput.X = value * 50.0f;
}
void ACharacterPawn::Look_YAxis(float value)
{
	TurnInput.Y = value * 50.0f;
}

void  ACharacterPawn::SpawnGalaxy()
{
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("Spawned Galaxy"));
	UE_LOG(LogTemp, Warning, TEXT("Spawned Galaxy"));
}

void  ACharacterPawn::DestroyGalaxy()
{
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("Destroyed Galaxy"));
	UE_LOG(LogTemp, Warning, TEXT("Destroyed Galaxy"));
}

