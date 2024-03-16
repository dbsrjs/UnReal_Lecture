// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameGameInstance_0316.generated.h"

 //제언리얼 게임의 총이 어떻게 구현될건지 정한단계 (설계) 
UCLASS()
class AGun : public AActor
{
    GENERATED_BODY()

public:
    AGun();
    AGun(FString GunName);
    ~AGun();
private:

    int BulletCount; //총알 갯수
    int FireSpeed; //총알 스피드
    float Range; // 총 범위
    int RelaodCount; //탄창 수
    FString GunName;//총 이름

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* GunBody; //스테틱 메시 컴포넌트 Body

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* FireEffect;

public://총으로 하고 싶은 기능
    void Fire();
    void Equip();
    void Reload();
};

UCLASS()
class UNREALCPP_0309_API UGameGameInstance_0316 : public UGameInstance
{
    GENERATED_BODY()
public:
    void InstanceFunction();

    UFUNCTION(EXEC)
    void GUNPROCESS();
public:
    UPROPERTY(EditAnywhere)
    class AGun* Ak47;
};