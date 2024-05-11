// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAIController.h"
#include "NavigationSystem.h" //네비게이션 시스템을 활용하기 위한 헤더 추가 
#include "Blueprint/AIBlueprintHelperLibrary.h" //AI Simple move to 기능을 사용하기 위해서 AI BlueprintLibrary를 가져온 것 
#include "BehaviorTree/BehaviorTree.h" //비헤비어 트리를 쓰기위한 헤더 추가
#include "BehaviorTree/BlackboardData.h" //블랙보드 데이터를 쓰기위한 헤더 추가 

#include "BehaviorTree/BlackboardComponent.h"

const FName AABAIController::HomePosKey(TEXT("HomePos"));
const FName AABAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AABAIController::TargetKey(TEXT("Target"));

AABAIController::AABAIController()
{
	RepeatInterval = 3.0f; // AIController 내에서  네비게이션에 따라서 이동할 함수를 불러주는 주기 
	
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/AI/BB_ABCharacter.BB_ABCharacter")); //내가 블루프린트클래스로 만든 BlackBoardObject를 C++ 가져오는 코드
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/AI/BT_ABCharacter.BT_ABCharacter")); //내가 블루프린트 클래스로 만든 비헤비어트리를 C++ 가져오는 코드 
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object; 
	}
}

void AABAIController::OnPossess(APawn* InPawn) //AIController가 Character(Pawn)이 빙의될때 세팅 ( BeginPlay랑 초기화 하는 타이밍 측면에서는 비슷하지만 - OnPossese 컨트롤러가 캐릭터 몸에들어갈때 초기화 하는 부분)
{
	Super::OnPossess(InPawn); //언리얼에서 만들어준 Onposses를 사용 ( 부모클래스) 내가 빙의가 됐을때 기본적으로 행해야하는 동작들을 수행하는 함수를 부르겠다. 
	//GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AABAIController::OnRepeatTimer, RepeatInterval, true);
	//인터벌 OnRepeatTimer라고 내가 만들어둔 함수를 RepeatInterval (3초)초마다 부르겠다

	UBlackboardComponent* BlackboardComp = Blackboard.Get(); // 블랙보드 컴포넌트 가져오는 코드 
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
	Super::OnUnPossess(); //내가 빙의가 풀릴때 기본적으로 행해야하는 동작들을 수행하는 함수를 부르겠다.
	//GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle); //타이머가 가지고 있는 Hangle(시간을 측정하는 자원을 반납한다)
}

void AABAIController::OnRepeatTimer() //RepeatInterval 따라서 반복하는 함수 (3초마다 불림)
{
	auto CurrentPawn = GetPawn(); //나의 Pawn 내가 빙의된 캐릭터(폰) 내가조종하는
	if (nullptr != CurrentPawn) 
	{
		UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		if (nullptr == NavSystem) //네비게이션 시스템을 가져와서 
			return;

		FNavLocation NextLocation; //네비게이션 중에 500cm (언리얼 1단위가 실제 1cm라서 5m 범위에서 내가 갈수있는 거리를 네비게이션 시스템을 이용해서 랜덤으로 알려달라)
		if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
		{	
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location); //네비게이션 시스템에서 받은 랜덤한 위치로 이동하게 해주세요
			UE_LOG(LogTemp, Warning, TEXT("Next Location %s"), *NextLocation.Location.ToString()); // 위치 출력
		}
	}
}
