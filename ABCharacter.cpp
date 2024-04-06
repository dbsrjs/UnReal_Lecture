// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacter.h"

// Sets default values
AABCharacter::AABCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Spring Arm(��ī��)�� �߰����ִ� �ڵ� 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	//ī�޶� �߰����ִ� �ڵ�
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//��ī���� ĸ�� ������Ʈ(ĳ���� �浹 ������Ʈ�� �ٿ��ִ� �ڵ�)
	SpringArm->SetupAttachment(GetCapsuleComponent());
	//��ī���� ī�޶� �ٿ��ִ� �ڵ�
	Camera->SetupAttachment(SpringArm);

	//�޽��� ������� ��ġ �� ȸ������ �����ϴ� �ڵ�
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	//��ī�� ���̸� 400���� ���ߴ� �ڵ�
	SpringArm->TargetArmLength = 400.0f;
	//��ī���� -15�� ��ŭ ������ �ڵ�
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	//ī�� ���� ���̷��� �޽��� (���۷��� ����θ� �̿��Ͽ� ����ϴ� ����)
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_CardBoard.SK_CharM_CardBoard"));
	if (SK_CARDBOARD.Succeeded())
	{
		//���̷�Ż �޽� ����
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	//���̷�Ż �ִϸ��̼��� �ִԺ������Ʈ ã�� �� ������� ������ִ� �Լ� 
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Characters/Mannequins/Animations/ABP_Warrior.ABP_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		//���̷�Ż �ִԺ������Ʈ ���� 
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);

	}

	SetControlMode(0);
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown); //���Ʒ� �����϶� ���Լ��� ���ڴ�.
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);// �¿� �����ϋ� ���Լ��� ���ڴ�.
	PlayerInputComponent->BindAxis(TEXT("Lookup"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);


}

void AABCharacter::UpDown(float NewAxisValue)
{
	//AddMovementInput(GetActorForwardVector(), NewAxisValue); //���ΰ��� Ű������ �չ������� �̵��ϰ� �ϰڴ�.
	//AddMovementInput(GetActorForwardVector(), NewAxisValue);
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AABCharacter::LeftRight(float NewAxisValue)
{
	//AddMovementInput(GetActorRightVector(), NewAxisValue); // �¿���� Ű�� ������ �翷���� �̵��ϰ� �ϰڴ�. 
	//AddMovementInput(GetActorRightVector(), NewAxisValue);
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AABCharacter::LookUp(float newAxisValue)
{
	AddControllerPitchInput(newAxisValue);
}

void AABCharacter::Turn(float newAxisValue)
{
	AddControllerYawInput(newAxisValue);
}

void AABCharacter::SetControlMode(int32 ControMode)
{
	if (ControMode == 0)
	{
		SpringArm->TargetArmLength = 450.0f;
		SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	}
}