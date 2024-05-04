// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder_1.h"
#include "NaveEnemigaNodriza.h"

// Sets default values
ABuilder_1::ABuilder_1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NaveNodrizas = GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass());
}

// Called when the game starts or when spawned
void ABuilder_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilder_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ANaveEnemigaNodriza* ABuilder_1::NaveNodriza()
{
	return NaveNodrizas;
}

void ABuilder_1::MovimientoNaveNodriza()
{
	//Implementación del movimiento de la nave nodriza
}

void ABuilder_1::DispararNaveNodriza()
{
}

