// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP_0309_API AABAIController : public AAIController
{
	GENERATED_BODY()

public:
	AABAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	static const FName HomePosKey;		//���� ��ġ
	static const FName PatrolPosKey;	// ������ ��ġ
	static const FName TargetKey;		//�÷��̾��� ��ġ

private:
	void OnRepeatTimer();

	FTimerHandle RepeatTimerHandle;
	float RepeatInterval;

	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;
};
