#include "ABPawn.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPawn.h"

// Sets default values
AABPawn::AABPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//캡슐 구성요소 생성
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	//매시 구성요소 생성
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMNET"));

	//스프링암 구성요소 생성 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	//카메라 구성요소 생성
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//클래스에 근본이되는 컴포넌트 == 캡슐로 지정
	RootComponent = Capsule; 
	// 외형(메시)는 캡슐에 붙임
	Mesh->SetupAttachment(Capsule);
	// 카메라붐(조정대)는 캡슐에 붙임
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	//기타 캡슐 / 메시 / 카메라 위치 조정 값
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	//폴더기반(상대경로) 기반 애셋 가져오기 
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded())
	{
		//에셋 메시에 적용하기 
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//애니메이션을 경로 기반으로 가져오는 역할
	static ConstructorHelpers::FClassFinder<UAnimInstance>WARRIOR_ANIM(TEXT("/Game/Books/Animations/Anim_Warrior.Anim_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		//애니메이션이 존재하면 애니메이션을 적용해준다.
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

}

// Called when the game starts or when spawned
void AABPawn::BeginPlay()
{
	Super::BeginPlay();
	// 외형( 메시에 애니메이션 모드를 정해준다)
}

// Called every frame
void AABPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//위아래로 움직이는 키를 폰이랑 연결해주는 함수(델리게이트)
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABPawn::UpDown);
	//좌우로 움직이는 키를 폰이랑 연결해주는 함수(델리게이트)
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABPawn::LeftRight);
}

void AABPawn::UpDown(float NewAxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), NewAxisValue);
	//무브먼트 입력값에 (Pawn의 앞방향 힘을 가해주는 함수) == 앞으로 가라
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AABPawn::LeftRight(float NewAxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), NewAxisValue);
	//무브먼트 입력값에 (Pawn의 오른쪽방향 힘을 가해주는 함수) == 앞으로 가라
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}
