// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	dimensionCargaOcupada = 300.0f;
	dimensionCargaDisponible = 700.0f;
	velocidad = 100.0f;
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	float PosicionInicialX = -500.0f;
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	float NuevaX = DeltaTime * velocidad;

	PosicionActual = FVector(PosicionActual.X + NuevaX, PosicionActual.Y, PosicionActual.Z);
	if (PosicionActual.X >= 0)
	{
		PosicionActual.X = PosicionInicialX;
	}
	SetActorLocation(PosicionActual);
}

void ANaveEnemigaTransporte::Cargar(float dimensionCarga, float pesoCarga)
{
	dimensionCargaOcupada = dimensionCargaDisponible - dimensionCarga;
}
