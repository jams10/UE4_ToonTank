// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapusleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapusleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void APawnBase::RotateTurretFunction(FVector LookAtTarget) 
{
	
}

void APawnBase::Fire() 
{
	
}

void APawnBase::HandleDestruction() 
{
	// - 공통 기능
	// 죽었을 때 효과 재생, 소리, 카메라 흔들림.

	// - 자식 클래스가 override
	// PawnTurret : 터렛이 죽음 -> 자기 자신 destroy
	// PawnTank : 플레이어가 죽음 -> 모든 컴포넌트 숨기기 & 입력 받지 않기.
}



