// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacter.h"

// Sets default values
AABCharacter::AABCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Spring Arm(셀카봉)을 추가해주는 코드 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	//카메라를 추가해주는 코드
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//셀카봉을 캡슐 컴포넌트(캐릭터 충돌 컴포넌트에 붙여주는 코드)
	SpringArm->SetupAttachment(GetCapsuleComponent());
	//셀카봉에 카메라를 붙여주는 코드
	Camera->SetupAttachment(SpringArm);

	//메시의 상대적인 위치 및 회전값을 조정하는 코드
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	//셀카봉 길이를 400으로 맞추는 코드
	SpringArm->TargetArmLength = 400.0f;
	//셀카봉을 -15도 만큼 돌리는 코드
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	//카드 보드 스켈레톤 메쉬를 (레퍼런스 상대경로를 이용하여 등록하는 과정)
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_CardBoard.SK_CharM_CardBoard"));
	if (SK_CARDBOARD.Succeeded())
	{
		//스켈레탈 메쉬 에셋
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	//스켈레탈 애니메이션을 애님블루프린트 찾을 걸 기반으로 등록해주는 함수 
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Characters/Mannequins/Animations/ABP_Warrior.ABP_Warrior_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		//스켈레탈 애님블루프린트 에셋 
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

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown); //위아래 움직일때 이함수를 쓰겠다.
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);// 좌우 움직일 이함수를 쓰겠다.
	PlayerInputComponent->BindAxis(TEXT("Lookup"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);


}

void AABCharacter::UpDown(float NewAxisValue)
{
	//AddMovementInput(GetActorForwardVector(), NewAxisValue); //위로가는 키누르면 앞방향으로 이동하게 하겠다.
	//AddMovementInput(GetActorForwardVector(), NewAxisValue);
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AABCharacter::LeftRight(float NewAxisValue)
{
	//AddMovementInput(GetActorRightVector(), NewAxisValue); // 좌우방향 키를 누르면 양옆으로 이동하게 하겠다. 
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
