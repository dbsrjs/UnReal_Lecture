// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class UNREALCPP_0309_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Pawn의 겉을 감싸는 충돌감지 구성요소(캡슐컴포넌트)
	UPROPERTY(VisibleAnywhere, Category=Collision)
	UCapsuleComponent* Capsule;
	//Pawn의 외형을 나타내는 겉모습(스켈레탈 메시)
	UPROPERTY(VisibleAnywhere, Category=Visual)
	USkeletalMeshComponent* Mesh;
	//둥둥떠다디게하는 무브먼트 구성요소(플로팅폰무브먼트 컴포넌트)
	UPROPERTY(VisibleAnywhere, Category=Movement)
	UFloatingPawnMovement* Movement;
	// 스프링암 컴포넌트 ( 카메라의고정대 역할을 하는 컴포넌트)
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;
	// 카메라 컴포넌트 캐릭터(폰)을 찍어주는 컴포넌트
	UPROPERTY(VisibleAnywhere, Category= Camera)
	UCameraComponent* Camera;

	///
private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
