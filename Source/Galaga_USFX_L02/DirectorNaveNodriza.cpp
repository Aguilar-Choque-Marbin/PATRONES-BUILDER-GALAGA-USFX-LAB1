// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveNodriza.h"

// Sets default values
ADirectorNaveNodriza::ADirectorNaveNodriza()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADirectorNaveNodriza::OrdenBuilder(AActor* Builder)
{
	Builder1 = Cast<IBuilderPrincipal>(Builder);
}

void ADirectorNaveNodriza::MovimientoNaveNodriza()
{
	Builder1->MovimientoNaveNodriza();
}

void ADirectorNaveNodriza::DispararNaveNodriza()
{
	Builder1->DispararNaveNodriza();
}

ANaveEnemigaNodriza* ADirectorNaveNodriza::NaveNodriza()
{
	return Builder1->NaveNodriza();
}

// Called when the game starts or when spawned
void ADirectorNaveNodriza::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorNaveNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

