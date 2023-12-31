// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// メッシュの作成
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	
	//アセットの設定
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	//作成に成功したか判定
		if (CubeVisualAsset.Succeeded())
			//パラメータ設定
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

	// アクタの位置を取得
	FVector NewLocation = GetActorLocation();

	// 現在の高さを算出
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	// Z（高さを設定）
	NewLocation.Z += DeltaHeight * FloatSpeedMove;

	// アクタの位置へ設定
	SetActorLocation(NewLocation);
}

