// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
    // CheckFireCondition 함수를 FireRate 마다 호출
    //          ▼ 전역 타이머 매니저
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireConditon, FireRate, true);
    // GetWorld()->GetTimerManager() = GetWorldTimerManager()
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireConditon() 
{
    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Check"));
}
