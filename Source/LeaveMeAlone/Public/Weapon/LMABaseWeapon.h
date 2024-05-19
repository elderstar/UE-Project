// LeaveMeAlone Game By Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMABaseWeapon.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAmmoDepleted);

class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FAmmoWeapon
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")

	int32 Bullets;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Clips;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool Infinite;

};
UCLASS()
class LEAVEMEALONE_API ALMABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ALMABaseWeapon();
	FOnAmmoDepleted OnAmmoDepleted; 
	 
	virtual void Tick(float DeltaTime) override;
	void Fire();
	void ChangeClip();
	bool IsCurrentClipFull() const;

protected:
	// Called when the game starts or when spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TraceDistance = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoWeapon AmmoWeapon;

	virtual void BeginPlay() override;

	void Shoot();
	bool isShooting = false;

	void DecrementBullets();
	bool IsCurrentClipEmpty() const;

private:
	const int32 MaxAmmo = 30;
	FAmmoWeapon CurrentAmmoWeapon;
};
