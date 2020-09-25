// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
    // CheckFireCondition 함수를 FireRate 마다 호출
    //          ▼ 전역 타이머 매니저
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireConditon, FireRate, true);
    // GetWorld()->GetTimerManager() = GetWorldTimerManager()

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));

}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
        // Fire
        UE_LOG(LogTemp, Warning, TEXT("Fire Condition Check"));
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
