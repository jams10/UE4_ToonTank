// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
    // CheckFireCondition �Լ��� FireRate ���� ȣ��
    //          �� ���� Ÿ�̸� �Ŵ���
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireConditon, FireRate, true);
    // GetWorld()->GetTimerManager() = GetWorldTimerManager()

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));

}

void APawnTurret::HandleDestruction() 
{
    // ����Ʈ ȿ�� ��� ���� base pawn Ŭ������ �Լ� ȣ��.
    Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireConditon() 
{
    // Check Player is null || is Dead
    if(!PlayerPawn)
    {
        return;
    }
    // If Player is in range then fire
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn)
    {
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
