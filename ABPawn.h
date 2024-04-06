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

	//Pawn�� ���� ���δ� �浹���� �������(ĸ��������Ʈ)
	UPROPERTY(VisibleAnywhere, Category=Collision)
	UCapsuleComponent* Capsule;
	//Pawn�� ������ ��Ÿ���� �Ѹ��(���̷�Ż �޽�)
	UPROPERTY(VisibleAnywhere, Category=Visual)
	USkeletalMeshComponent* Mesh;
	//�յն��ٵ���ϴ� �����Ʈ �������(�÷����������Ʈ ������Ʈ)
	UPROPERTY(VisibleAnywhere, Category=Movement)
	UFloatingPawnMovement* Movement;
	// �������� ������Ʈ ( ī�޶��ǰ����� ������ �ϴ� ������Ʈ)
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;
	// ī�޶� ������Ʈ ĳ����(��)�� ����ִ� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category= Camera)
	UCameraComponent* Camera;

	///
private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
