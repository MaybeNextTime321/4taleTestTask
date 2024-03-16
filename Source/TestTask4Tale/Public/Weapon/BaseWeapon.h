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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ShootAction")
	void Shoot();
	virtual void Shoot_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ShootAction")
	void Reload();
	virtual void Reload_Implementation();

	UFUNCTION(BlueprintCallable, Category = "WeaponData")
	void GetAmmoData(int32& BulletCount, int32& ClipsCount);

	UPROPERTY(EditDefaultsOnly, Category = WeaponData)
	FWeaponData WeaponData;



protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Weapon")
	USkeletalMeshComponent* SkeletalMesh;

private:
	int32 CurrentBullet;
	int32 CurrentClips;

};
