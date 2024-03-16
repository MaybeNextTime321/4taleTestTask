// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/WeaponComponent.h"
#include "Weapon/BaseWeapon.h"
#include "TestTask4Tale/TestTask4TaleCharacter.h"
// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}




// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	CurrentWeaponIndex = 0;
	EquipWeapon(CurrentWeaponIndex);
	// ...
	checkf(!WeaponSoket.ToString().IsEmpty(), TEXT("Write Weapon Socket Name"));
	checkf(!WeaponEquipSoket.ToString().IsEmpty(), TEXT("Write Weapon Equip Socket Name"));
	checkf(AmmoData.Num() > 0 , TEXT("Add at least one weapon"));

	
}

void UWeaponComponent::StartShooting()
{
	if (!CurrentWeapon)
	{
		return;
	}

	CurrentWeapon->Shoot();

}

void UWeaponComponent::SpawnWeapon()
{
	ACharacter* Owner = Cast<ACharacter>(GetOwner());
	for (auto Weapon : AmmoData)
	{
		CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(Weapon.Get());
		CurrentWeapon->SetOwner(GetOwner());
		Weapons.Add(CurrentWeapon);
	}
	

}

void UWeaponComponent::EquipWeapon(int32 WeaponIndex)
{
	if (WeaponIndex < 0 && WeaponIndex > Weapons.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Weapon Index"));
		return;
	}

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (CurrentWeapon)
	{
		AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponSoket);
	}

	CurrentWeapon = Weapons[WeaponIndex];
	CurrentReloadAnimMontage = CurrentWeapon->WeaponData.ReloadMontage;
	AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponEquipSoket);
	
	OwnerCharacter->PlayAnimMontage(CurrentReloadAnimMontage);
}

void UWeaponComponent::AttachWeaponToSoket(ABaseWeapon* Weapon, USceneComponent* SceneComponent, FName SocketName)
{
	FAttachmentTransformRules Rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(SceneComponent, Rules, SocketName);
}




