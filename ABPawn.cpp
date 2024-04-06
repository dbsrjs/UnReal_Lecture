#include "ABPawn.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPawn.h"

// Sets default values
AABPawn::AABPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ĸ�� ������� ����
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	//�Ž� ������� ����
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMNET"));

	//�������� ������� ���� 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	//ī�޶� ������� ����
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//Ŭ������ �ٺ��̵Ǵ� ������Ʈ == ĸ���� ����
	RootComponent = Capsule; 
	// ����(�޽�)�� ĸ���� ����
	Mesh->SetupAttachment(Capsule);
	// ī�޶��(������)�� ĸ���� ����
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	//��Ÿ ĸ�� / �޽� / ī�޶� ��ġ ���� ��
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	//�������(�����) ��� �ּ� �������� 
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded())
	{
		//���� �޽ÿ� �����ϱ� 
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//�ִϸ��̼��� ��� ������� �������� ����
	static ConstructorHelpers::FClassFinder<UAnimInstance>WARRIOR_ANIM(TEXT("/Game/Books/Animations/Anim_Warrior.Anim_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		//�ִϸ��̼��� �����ϸ� �ִϸ��̼��� �������ش�.
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

}

// Called when the game starts or when spawned
void AABPawn::BeginPlay()
{
	Super::BeginPlay();
	// ����( �޽ÿ� �ִϸ��̼� ��带 �����ش�)
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

	//���Ʒ��� �����̴� Ű�� ���̶� �������ִ� �Լ�(��������Ʈ)
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABPawn::UpDown);
	//�¿�� �����̴� Ű�� ���̶� �������ִ� �Լ�(��������Ʈ)
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABPawn::LeftRight);
}

void AABPawn::UpDown(float NewAxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), NewAxisValue);
	//�����Ʈ �Է°��� (Pawn�� �չ��� ���� �����ִ� �Լ�) == ������ ����
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AABPawn::LeftRight(float NewAxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), NewAxisValue);
	//�����Ʈ �Է°��� (Pawn�� �����ʹ��� ���� �����ִ� �Լ�) == ������ ����
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

