// LeaveMeAlone Game By Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;
class ULMAWeaponComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();
	
	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation") 
	UAnimMontage* DeathMontage;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isSprinting = false;

	UFUNCTION()
	void OnDeath();

	void StartSprinting();
	void StopSprinting();
	void UpdateStamina(float DeltaTime);

private:
	float YRotation = -75.0f;
	float FOV = 55.0f;
	float SprintVelocity = 600.0f;
	float DefaultWalkSpeed = 300.0f;
	float Stamina = 100.0f;
	float StaminaMax = 100.0f;
	float StaminaDelta = 5.0f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void ChangeArmLength(float Value);
	
	void RotationPlayerOnCursor();
	void OnHealthChanged(float NewHealth);
	bool IsMovingBackwards() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
