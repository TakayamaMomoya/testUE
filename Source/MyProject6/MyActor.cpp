// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V���̍쐬
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	
	//�A�Z�b�g�̐ݒ�
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	//�쐬�ɐ�������������
		if (CubeVisualAsset.Succeeded())
			//�p�����[�^�ݒ�
			VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
	VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

void AMyActor::OnConstruction(const FTransform& transform)
{

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(
		(uint64)-1,
		2.0f,
		FLinearColor::Red.ToFColor(true),
		TEXT("HELLO WORLD")
	);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �A�N�^�̈ʒu���擾
	FVector NewLocation = GetActorLocation();

	// ���݂̍������Z�o
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	// Z�i������ݒ�j
	NewLocation.Z += DeltaHeight * 20.0f;

	// �A�N�^�̈ʒu�֐ݒ�
	SetActorLocation(NewLocation);
}

