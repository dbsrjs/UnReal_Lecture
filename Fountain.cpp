// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"   //Fountain ����� ���� �س��� �� �̸����� ������ ���ڴٴ� �ǹ�
#include "Components/SceneComponent.h"  //�� ������Ʈ ��� ���ִ� �κ��� �𸮾� �󿡼� ���� �����س��� ������Ʈ���� ����ϱ� ���� �Լ����� ������ ���ڴ�.

// Sets default values
AFountain::AFountain()//���� ���� �м���� Ŭ������ �����ϴ� �ܰ迡�� �۵��ؾ��� ��ɵ��� ��Ƶ� ��.
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));//�𸮾� �󿡼� ������ߵ� �м��� ����� �𸮾� ���󿡼� �������
    Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));//������ �󿡼� ��������� �� ����� �𸮾� ���󿡼� �������
    Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));//�м��� ���� �κ��� �𸮾� ���󿡼� �������
    Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));//�м��� �� Ƣ��� �κ��� �𸮾� ���󿡼� �������

    RootComponent = Body;   //�𸮾� �󿡼� ���� ���� �м��� ����(�Ѹ�)�� �� �κ��� Body(���� �м��� �����̶�� ������ �κ���) ���� ���� �м��� ������ �Ǵ� �κ�.
    Water->SetupAttachment(Body);//Attach '���̴�'��� �����, ������ �м� ���뿡 �پ�����.
    Light->SetupAttachment(Body);// ` ` ` `
    Splash->SetupAttachment(Body);// ` ` ` `

    //�𸮾��� 1f = 1cm
    Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));    //Water�� Vector3
    Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));    //Light�� Vector3
    Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));   //Splash�� Vector3
}

// Called when the game starts or when spawned
//���� ���۽� ����Ǵ� �Լ�(Start)
void AFountain::BeginPlay()
{
    Super::BeginPlay(); //��� ���� ���� ���� �Ŀ� ����.

}

// Called every frame
// ���������� �׷����� ���� �Ҹ���� �Լ� (�ʴ� 45~120��)(Update)
void AFountain::Tick(float DeltaTime)
{
    //��� �Լ���°� ǥ���ϱ� ���� 'AFountain' ��� �̸��� ������ �������� ������
    Super::Tick(DeltaTime); //��� ���� ���� ���� �Ŀ� ����.
}