// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class ABaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK4TALE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	int32 CurrentWeaponIndex;
	ABaseWeapon* CurrentWeapon;

private:	
	UPROPERTY(EditAnywhere, Category = WeaponData)
	TArray<TSubclassOf<ABaseWeapon>> AmmoData;
	void SpawnWeapon();
	void EquipWeapon(int32 WeaponIndex);
	TArray<ABaseWeapon *> Weapons;

	UPROPERTY(EditAnywhere, Category = WeaponData)
	FName WeaponSoket;

	UPROPERTY(EditAnywhere, Category = WeaponData)
	FName WeaponEquipSoket;

	void AttachWeaponToSoket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, FName SocketName);
	
	UAnimMontage* CurrentReloadAnimMontage;

};
