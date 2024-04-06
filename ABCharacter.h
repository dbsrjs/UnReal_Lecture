// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"


UCLASS()//클래스를 언리얼에 등록하는 방법.
class UNREALCPP_0309_API AABCharacter : public ACharacter
{
	GENERATED_BODY()	//클래스를 언리얼에 등록하겠다.

public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, category = Camera)
    USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere, category = Camera)
    UCameraComponent* Camera;

private:
    void UpDown(float NewAxisValue);
    void LeftRight(float NewAxisValue);
    void LookUp(float newAxisValue);
    void Turn(float newAxisValue);
    void SetControlMode(int32 ControMode);

};