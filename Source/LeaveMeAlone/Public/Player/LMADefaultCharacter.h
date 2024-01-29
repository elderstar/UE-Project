// LeaveMeAlone Game By Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ArmLength = 1400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MinArmLength = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxArmLength = 1800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ZoomSpeed = 100.0f;

private:
	float YRotation = -75.0f;
	float FOV = 55.0f;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void ChangeArmLength(float Value);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
