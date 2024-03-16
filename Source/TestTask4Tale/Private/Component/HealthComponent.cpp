// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/HealthComponent.h"
#include <Net/UnrealNetwork.h>

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, Health);
}

void UHealthComponent::ReceiveDamage(int32 DamageAmount)
{
	if (!bIsAlive)
	{
		return;
	}

	int32 NewHealth = Health - DamageAmount;
	Health = FMath::Clamp(NewHealth, 0, 100);
	OnHealthChangedDelegate.Broadcast(Health);

	if(Health == 0) 
	{
		bIsAlive = false;
	}
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = DefaultHealth;
	OnHealthChangedDelegate.Broadcast(Health);

	SetIsReplicated(true);
}



