// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInAttackRang.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP_0309_API UBTDecorator_IsInAttackRang : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_IsInAttackRang();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
