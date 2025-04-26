// Fill out your copyright notice in the Description page of Project Settings.


#include "Health_Component.h"

// Sets default values for this component's properties
UHealth_Component::UHealth_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;
	_maxHealth = 100.f;
	// ...
}


// Called when the game starts
void UHealth_Component::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealth_Component::DamageTaken);
	// ...
	
}

void UHealth_Component::DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* causer)
{
	_currentHealth = FMath::Max(_currentHealth - damage, 0.0f);
	OnDamaged.Broadcast(instigator, damage, _currentHealth);
	if (_currentHealth <= 0.0f)
	{
		OnComponentDead.Broadcast(instigator);
	}
}
