// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, int32, NewHealth);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class TESTTASK4TALE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	bool IsAlive() const { return bIsAlive; }

	void ReceiveDamage(int32 DamageAmount);

	UPROPERTY(EditAnywhere, Category = Health, meta = (ClampMin = "0", ClampMax = "100.0"))
	int32 DefaultHealth = 0;

	FOnHealthChanged OnHealthChangedDelegate;



protected:
	virtual void BeginPlay() override;

private:	
	bool bIsAlive = true;
	int32 Health = 0;

};
