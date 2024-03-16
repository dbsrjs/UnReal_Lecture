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
	Animal()//������ (Ŭ������ ó�� ����� �� �� ������ �Ҹ��� �Լ�)
	{
		//���� �� �� �ҷ� ��
		//������ �ʱ�ȭ(�⺻���� ������ ����)
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Yellow, FString::Printf(TEXT("Tiger!!!")));
	}

	~Animal()//�Ҹ���
	{
		//���� �� �ҷ� ��
		//������ �ּҰ��̳� ��� �ִ� �������� ����
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
		//Iostream�� �������� �ʾұ� ������ ���� ����
		//std::cout << "�� ������ food : " << food << std::endl;
		//std::cout << "�� ������ weight : " << weight << std::endl;

		//�𸮾� �󿡼� �α׸� ����� �� �ִ� ���(C++ Cout�� ����)
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
	UFUNCTION(Exec)	//Exec : Execute�� ���ڷ� �𸮾�󿡼� ġƮŰ	
		void PlayMain()	//���� �Լ��� �𸮾󿡼��� ���� �����Ǿ� �־� ����ϰ� ��ü ����
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