// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;

USTRUCT()
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = WeaponData, meta = (ClampMin = "0"))
	int32 ClipsCount;

	UPROPERTY(EditAnywhere, Category = WeaponData, meta = (ClampMin = "0"))
	int32 BulletCount;

	UPROPERTY(EditAnywhere, Category = WeaponData)
	bool bInfinityShoot;

	UPROPERTY(EditDefaultsOnly, Category = WeaponData);
	UAnimMontage* ReloadMontage;
};

UCLASS()
class TESTTASK4TALE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();
	virtual void Shoot();
	virtual void Reload();

	UPROPERTY(EditDefaultsOnly, Category = WeaponData)
	FWeaponData WeaponData;

protected:
	virtual void BeginPlay() override;



private:	


	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USkeletalMeshComponent* SkeletalMesh;

};
