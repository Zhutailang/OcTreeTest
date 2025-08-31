// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BiodsLibrary.h"
#include "BiodsManager.generated.h"

class AStaticMeshActor;
/**
 * 
 */
UCLASS()
class ALGORITHMTEST_API UBiodsManager : public UWorldSubsystem,public FTickableGameObject
{
	GENERATED_BODY()
public:
	// ����ʵ�ֵ� FTickableGameObject �ӿ�
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;


	// ��ѡ������ Tick ˳��Ĭ�Ϸ��� nullptr��
	virtual ETickableTickType GetTickableTickType() const override;

	UFUNCTION(BlueprintCallable)
	void Init(UStaticMesh* _InstanceMesh, int32 _BiodsNum,FTransform SpawnTransform);

	UPROPERTY()
	TArray<FBiod> Biods;
	UPROPERTY()
	TArray<AStaticMeshActor*> BiodInstances;
	
	bool IsStarted=false;


	UStaticMesh* InstanceMesh;
	int32 BiodsNum;

	float SeperationRate=1.f;
	float AlignmentRate=1.f;
	float CohesionRate=1.f;
};
