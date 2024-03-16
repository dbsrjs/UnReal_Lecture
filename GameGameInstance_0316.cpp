// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGameInstance_0316.h"

AGun::AGun()
{
    RelaodCount = 0;
    UE_LOG(LogTemp, Warning, TEXT("Create Gun Gang %s"), *GunName); //String ��� �־��µ� �߾ȵǸ� *���̱�

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    GunBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
    FireEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));

    RootComponent = GunBody;
    FireEffect->SetupAttachment(GunBody);
    FireEffect->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));

    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        SM_AK(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/AR4/SK_AR4"));
    if (SM_AK.Succeeded())
    {
        GunBody->SetStaticMesh(SM_AK.Object);
    }
}

AGun::AGun(FString _GunName)
{
    RelaodCount = 0;
    GunName = _GunName;
    UE_LOG(LogTemp, Warning, TEXT("Create Gun Gang %s"), *GunName); //String ��� �־��µ� �߾ȵǸ� *���̱�

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    GunBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
    FireEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));

    RootComponent = GunBody;
    FireEffect->SetupAttachment(GunBody);
    FireEffect->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));

    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        SM_AK(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/AR4/SK_AR4"));
    if (SM_AK.Succeeded())
    {
        GunBody->SetStaticMesh(SM_AK.Object);
    }
}

AGun::~AGun()
{
}

//���� ��Ŭ������ �� h / cpp 
//�Լ� ��ɵ��� �������� ���ſ��� 
// �����ϱ� ���ҷ��� ���������� ���� 
void AGun::Fire() // ��� �տ� ::(������ ǥ��) 
{

}

void AGun::Equip() //�̸�ǥ ������. 
{

}

void AGun::Reload()
{
}

void UGameGameInstance_0316::InstanceFunction()// ��� �տ� ::(������ ǥ��)
{
}

void UGameGameInstance_0316::GUNPROCESS()
{
    //AGun Ak47("AK47");
    //AGun M16("M16");
    //AGun M4("M4");
    //AGun K2("K2");

    UWorld* world = GetWorld();
    FActorSpawnParameters SpawnParams;
    FRotator rotator = FRotator(0.0f, 0.0f, 0.f);;
    FVector  SpawnLocation = FVector(0.0f, 0.0f, 700.f);

    Ak47 = world->SpawnActor<AGun>(AGun::StaticClass(), SpawnLocation, rotator, SpawnParams);
    Ak47->Fire();
}