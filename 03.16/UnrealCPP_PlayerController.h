// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UnrealCPP_PlayerController.generated.h"

/**
 * 
 */
class Animal {	
private:
	int food;
	int weight;

public:
	Animal()//생성자 (클래스가 처음 만들어 질 때 무조건 불리는 함수)
	{
		//시작 할 때 불러 줌
		//데이터 초기화(기본적인 데이터 세팅)
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Yellow, FString::Printf(TEXT("Tiger!!!")));
	}

	~Animal()//소멸자
	{
		//끝날 때 불러 줌
		//포인터 주소값이나 잡고 있는 변수들을 정리
	}

	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}


	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}

	void view_state() {
		//Iostream을 포함하지 않았기 때문에 나는 에러
		//std::cout << "이 동물의 food : " << food << std::endl;
		//std::cout << "이 동물의 weight : " << weight << std::endl;

		//언리얼 상에서 로그를 찍어줄 수 있는 기능(C++ Cout와 동일)
		UE_LOG(LogTemp, Warning, TEXT("this animal food %d"), food);
		UE_LOG(LogTemp, Warning, TEXT("this animal weight %d"), weight);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("this animal food %d"), food));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("this animal weight %d"), weight));
		}
	}
};

UCLASS()
class UNREALCPP_0309_API AUnrealCPP_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Exec)	//Exec : Execute의 약자로 언리얼상에서 치트키	
		void PlayMain()	//메인 함수가 언리얼에서는 따로 구현되어 있어 비슷하게 대체 구현
	{
		int FoodAmount = 100;
		int AnimalWeight = 50;
		int AmountIncrease = 30;

		Animal animal;
		animal.set_animal(FoodAmount, AnimalWeight);
		animal.increase_food(AmountIncrease);

		animal.view_state();
	};

	void print(int x) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("int : %d"), x));
	}

	void print(char x) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("char : %c"), x));
	}

	void print(double x) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("double : %lf"), x));
	}

	UFUNCTION(Exec)
	void Overloading()
	{
		int a = 1;
		char b = 'c';
		double c = 3.2f;

		print(a);
		print(b);
		print(c);
	}

	UFUNCTION(Exec)
	void Sdafwe() 
	{
		Animal panda;
		Animal rabbit;
		Animal tiger;
	}
};
