// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGameInstance_0316.h"

AGun::AGun()
{
    RelaodCount = 0;
    UE_LOG(LogTemp, Warning, TEXT("Create Gun Gang %s"), *GunName); //String 어디 넣었는데 잘안되면 *붙이기

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
    UE_LOG(LogTemp, Warning, TEXT("Create Gun Gang %s"), *GunName); //String 어디 넣었는데 잘안되면 *붙이기

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

//보통 한클래스가 한 h / cpp 
//함수 기능들을 페이지를 뺀거에요 
// 관리하기 편할려고 페이지들을 뺀거 
void AGun::Fire() // 기능 앞에 ::(내꺼임 표시) 
{

}

void AGun::Equip() //이름표 딱지다. 
{

}

void AGun::Reload()
{
}

void UGameGameInstance_0316::InstanceFunction()// 기능 앞에 ::(내꺼임 표시)
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