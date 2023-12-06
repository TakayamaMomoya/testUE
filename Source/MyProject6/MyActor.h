// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT6_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// staticMeshコンポーネントを追加
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent *VisualMesh;

	virtual void OnConstruction(const FTransform& transform) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "FloatingProperty")
	float FloatSpeedMove = 20.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
};
