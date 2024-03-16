// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SceletalMesh");
	SetRootComponent(SkeletalMesh);


}

void ABaseWeapon::Reload_Implementation()
{
}

void ABaseWeapon::Shoot_Implementation()
{
}

void ABaseWeapon::GetAmmoData(int32& BulletCount, int32& ClipsCount)
{
	BulletCount = CurrentBullet;
	ClipsCount = CurrentClips;
}



void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	CurrentBullet = WeaponData.BulletCount;
	CurrentClips = WeaponData.ClipsCount;
}



