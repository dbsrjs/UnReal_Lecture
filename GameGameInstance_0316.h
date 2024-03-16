// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameGameInstance_0316.generated.h"

 //���𸮾� ������ ���� ��� �����ɰ��� ���Ѵܰ� (����) 
UCLASS()
class AGun : public AActor
{
    GENERATED_BODY()

public:
    AGun();
    AGun(FString GunName);
    ~AGun();
private:

    int BulletCount; //�Ѿ� ����
    int FireSpeed; //�Ѿ� ���ǵ�
    float Range; // �� ����
    int RelaodCount; //źâ ��
    FString GunName;//�� �̸�

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* GunBody; //����ƽ �޽� ������Ʈ Body

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* FireEffect;

public://������ �ϰ� ���� ���
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