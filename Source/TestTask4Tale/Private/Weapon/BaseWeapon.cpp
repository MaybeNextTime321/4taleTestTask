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

void ABaseWeapon::Shoot()
{
}

void ABaseWeapon::Reload()
{
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}



