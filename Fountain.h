// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//������ ���� ����� CPP���� �� ������ ���� �س��� �������� �����Դϴ�.
//�׷��� H�� ������ �ٸ� �ڵ���� �̐a�� ������ �־��
//#include ���� C �� �� Iostream/ Studio (��͵��� ����� ���� ��ɵ��� �����Դ��Ű�)

#include "CoreMinimal.h"    //�𸮾� �ھ�(�ٽ�) ����� ���ڴ�. �𸮾� �������� ����� ���ڴ�. �𸮾� CPP���� ���� �ٵ��ϴ�.
#include "Components/PointLightComponent.h" //Components/PointLightComponet�� �߰��� �۴�Ⱑ ������ ���� ����
//����Ʈ ����Ʈ ������Ʈ�� �� �� �ְ� ����
#include "Particles/ParticleSystemComponent.h"
//��ƼŬ ������ �ִ� ȿ�� ������Ʈ�� ����ϰڴٶ�� ����
#include "GameFramework/Actor.h"
//���������ӿ�ũ / ���� ����� �Ǿ��ִ°� ���������ӿ�ũ ������ ����� ����� �̸� ����� ������ ���ڴ�.
#include "Fountain.generated.h"
//���� ���� Fountain�̶�� Ŭ������ �𸮾�� ��Ͻ����� (C++�� �𸮾��� �������� �ϳ�)

UCLASS()//�𸮾� �� Ŭ������ ��� ������
class UNREALCPP_0309_API AFountain : public AActor //Actor�� ��� ���� �м� ����
{
    GENERATED_BODY()    //�𸮾󿡸� �����ϴ� ����(���� �ۼ��� �ڵ��� ���븦 ������ִ� ����)

public:
    // Sets default values for this actor's properties
    AFountain();    //������(���� ���� Ŭ������ �Ȱ��� �̸��� ����, Ŭ������ ������� �� ó�� �Ҹ��� �Լ�)

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override; // ������ �����Ҷ� ó�� �Ҹ��� �Լ� 

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override; // ���������� �׷����� ���� �Ҹ���� �Լ� (�ʴ� 45~120��)

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Body; //����ƽ �޽� ������Ʈ Body

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Water; //Static Mesh ������Ʈ ����(��)

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class UPointLightComponent* Light; // ������ 

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* Splash; // ��Ƣ��� ȿ�� 

    UPROPERTY(EditAnywhere, Category = ID)
    int32 ID;

    //����� CPP�� �̸��� �Ȱ��ٸ� �̾��� �ִٰ� �����ϸ� ��
    //����� �ִ� ������ �� CPP�� �ű�ų�
};