// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//헤더라는 개념 헤더는 CPP에서 쓸 용어들을 정리 해놓는 목차같은 개념입니다.
//그래서 H만 가지고 다른 코드들의 이륾을 쓸수가 있어요
//#include 저희가 C 할 때 Iostream/ Studio (요것들은 출력을 위한 기능들을 가져왔던거고)

#include "CoreMinimal.h"    //언리얼에 코어(핵심) 기능을 쓰겠다. 언리얼 전반적인 기능을 쓰겠다. 언리얼 CPP에서 거의 다들어갑니다.
#include "Components/PointLightComponent.h" //Components/PointLightComponet는 중간에 작대기가 있으면 폴더 구조
//포인트 라이트 컴포넌트를 쓸 수 있게 포함
#include "Particles/ParticleSystemComponent.h"
//파티클 폴더에 있는 효과 컴포넌트를 사용하겠다라고 정의
#include "GameFramework/Actor.h"
//게임프레임워크 / 액터 헤더가 되어있는건 게임프레임워크 게임을 만드는 방법을 미리 만들어 놓은걸 쓰겠다.
#include "Fountain.generated.h"
//내가 만든 Fountain이라는 클래서를 언리얼상에 등록시켜줘 (C++과 언리얼의 차이점중 하나)

UCLASS()//언리얼에 내 클래스를 등록 시켜줌
class UNREALCPP_0309_API AFountain : public AActor //Actor를 상속 받은 분수 액터
{
    GENERATED_BODY()    //언리얼에만 존재하는 문법(내가 작성한 코드의 뼈대를 만들어주는 문법)

public:
    // Sets default values for this actor's properties
    AFountain();    //생성자(내가 만든 클래스와 똑같은 이름을 갖고, 클래스가 만들어질 때 처음 불리는 함수)

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override; // 게임이 시작할때 처음 불리는 함수 

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override; // 한프레임이 그려지는 동안 불리우는 함수 (초당 45~120번)

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Body; //스테틱 메시 컴포넌트 Body

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Water; //Static Mesh 컴포넌트 워터(물)

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class UPointLightComponent* Light; // 라이팅 

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* Splash; // 물튀기는 효과 

    UPROPERTY(EditAnywhere, Category = ID)
    int32 ID;

    //헤더랑 CPP는 이름이 똑같다면 이어져 있다고 생각하면 됨
    //헤더에 있는 문구들 다 CPP에 옮기거나
};