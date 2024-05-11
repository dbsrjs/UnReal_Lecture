// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAIController.h"
#include "NavigationSystem.h" //�׺���̼� �ý����� Ȱ���ϱ� ���� ��� �߰� 
#include "Blueprint/AIBlueprintHelperLibrary.h" //AI Simple move to ����� ����ϱ� ���ؼ� AI BlueprintLibrary�� ������ �� 
#include "BehaviorTree/BehaviorTree.h" //������ Ʈ���� �������� ��� �߰�
#include "BehaviorTree/BlackboardData.h" //������ �����͸� �������� ��� �߰� 

#include "BehaviorTree/BlackboardComponent.h"

const FName AABAIController::HomePosKey(TEXT("HomePos"));
const FName AABAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AABAIController::TargetKey(TEXT("Target"));

AABAIController::AABAIController()
{
	RepeatInterval = 3.0f; // AIController ������  �׺���̼ǿ� ���� �̵��� �Լ��� �ҷ��ִ� �ֱ� 
	
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/AI/BB_ABCharacter.BB_ABCharacter")); //���� �������ƮŬ������ ���� BlackBoardObject�� C++ �������� �ڵ�
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/AI/BT_ABCharacter.BT_ABCharacter")); //���� �������Ʈ Ŭ������ ���� ������Ʈ���� C++ �������� �ڵ� 
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object; 
	}
}

void AABAIController::OnPossess(APawn* InPawn) //AIController�� Character(Pawn)�� ���ǵɶ� ���� ( BeginPlay�� �ʱ�ȭ �ϴ� Ÿ�̹� ���鿡���� ��������� - OnPossese ��Ʈ�ѷ��� ĳ���� �������� �ʱ�ȭ �ϴ� �κ�)
{
	Super::OnPossess(InPawn); //�𸮾󿡼� ������� Onposses�� ��� ( �θ�Ŭ����) ���� ���ǰ� ������ �⺻������ ���ؾ��ϴ� ���۵��� �����ϴ� �Լ��� �θ��ڴ�. 
	//GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AABAIController::OnRepeatTimer, RepeatInterval, true);
	//���͹� OnRepeatTimer��� ���� ������ �Լ��� RepeatInterval (3��)�ʸ��� �θ��ڴ�

	UBlackboardComponent* BlackboardComp = Blackboard.Get(); // ������ ������Ʈ �������� �ڵ� 
	if (UseBlackboard(BBAsset, BlackboardComp))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			UE_LOG(LogTemp, Error, TEXT("AIController Couldnt run Behavior Tree!"));
		}
	}
}

void AABAIController::OnUnPossess()
{
	Super::OnUnPossess(); //���� ���ǰ� Ǯ���� �⺻������ ���ؾ��ϴ� ���۵��� �����ϴ� �Լ��� �θ��ڴ�.
	//GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle); //Ÿ�̸Ӱ� ������ �ִ� Hangle(�ð��� �����ϴ� �ڿ��� �ݳ��Ѵ�)
}

void AABAIController::OnRepeatTimer() //RepeatInterval ���� �ݺ��ϴ� �Լ� (3�ʸ��� �Ҹ�)
{
	auto CurrentPawn = GetPawn(); //���� Pawn ���� ���ǵ� ĳ����(��) ���������ϴ�
	if (nullptr != CurrentPawn) 
	{
		UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		if (nullptr == NavSystem) //�׺���̼� �ý����� �����ͼ� 
			return;

		FNavLocation NextLocation; //�׺���̼� �߿� 500cm (�𸮾� 1������ ���� 1cm�� 5m �������� ���� �����ִ� �Ÿ��� �׺���̼� �ý����� �̿��ؼ� �������� �˷��޶�)
		if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
		{	
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location); //�׺���̼� �ý��ۿ��� ���� ������ ��ġ�� �̵��ϰ� ���ּ���
			UE_LOG(LogTemp, Warning, TEXT("Next Location %s"), *NextLocation.Location.ToString()); // ��ġ ���
		}
	}
}
