// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health_Component.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDeadSignature, AController*, causer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FComponentDamagedSignature, AController*, causer, float, damage, float, newHealth);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_PROJECT_API UHealth_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealth_Component();
	UPROPERTY(BlueprintAssignable) FComponentDeadSignature OnComponentDead;
	UPROPERTY(BlueprintAssignable) FComponentDamagedSignature OnDamaged;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) float _currentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float _maxHealth;
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION() void DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* causer);

public:	
	
		
};
