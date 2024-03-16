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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	bool IsAlive() const { return bIsAlive; }
	
	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(int32 DamageAmount);

	UPROPERTY(EditAnywhere, Category = Health, meta = (ClampMin = "0", ClampMax = "100.0"))
	int32 DefaultHealth = 0;

	FOnHealthChanged OnHealthChangedDelegate;

	UFUNCTION(BlueprintCallable)
	int32 GetHP() { return Health; }


protected:
	virtual void BeginPlay() override;

	UPROPERTY(Replicated)
	int32 Health = 0;
private:	
	bool bIsAlive = true;
	

};
