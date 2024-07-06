// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"   //Fountain 헤더에 정의 해놓은 내 이름들을 가져다 쓰겠다는 의미
#include "Components/SceneComponent.h"  //씬 컴포넌트 헤더 되있는 부분은 언리얼 상에서 내가 정의해놓은 컴포넌트들을 등록하기 위해 함수들을 빌려서 쓰겠다.

// Sets default values
AFountain::AFountain()//내가 만든 분수라는 클래스를 생성하는 단계에서 작동해야할 기능들을 모아둔 곳.
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));//언리얼 상에서 보여줘야될 분수의 모습을 언리얼 세상에서 만들어줌
    Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));//연리얼 상에서 보여줘야할 물 모습을 언리얼 세상에서 만들어줌
    Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));//분수의 조명 부분을 언리얼 세상에서 만들어줌
    Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));//분수의 물 튀기는 부분을 언리얼 세상에서 만들어줌

    RootComponent = Body;   //언리얼 상에서 내가 만든 분수가 중점(뿌리)가 될 부분은 Body(내가 분수의 몸통이라고 만들어둔 부분이) 내가 만든 분수의 중점이 되는 부분.
    Water->SetupAttachment(Body);//Attach '붙이다'라는 영어고, 조명은 분수 몸통에 붙어있음.
    Light->SetupAttachment(Body);// ` ` ` `
    Splash->SetupAttachment(Body);// ` ` ` `

    //언리얼은 1f = 1cm
    Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));    //Water의 Vector3
    Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));    //Light의 Vector3
    Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));   //Splash의 Vector3
}

// Called when the game starts or when spawned
//게임 시작시 실행되는 함수(Start)
void AFountain::BeginPlay()
{
    Super::BeginPlay(); //상속 관련 강의 끝난 후에 설명.

}

// Called every frame
// 한프레임이 그려지는 동안 불리우는 함수 (초당 45~120번)(Update)
void AFountain::Tick(float DeltaTime)
{
    //헤더 함수라는걸 표현하기 위해 'AFountain' 라고 이름이 써져서 소유권을 주장함
    Super::Tick(DeltaTime); //상속 관련 강의 끝난 후에 설명.
}
