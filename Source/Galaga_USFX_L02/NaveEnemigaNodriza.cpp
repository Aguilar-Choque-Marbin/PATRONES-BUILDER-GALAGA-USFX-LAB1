// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "Galaga_USFX_L02Projectile.h"

void ANaveEnemigaNodriza::BeginPlay()
{
}

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
}

void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	float TiempoDeDisparo = 0.0f;
	float Intervalo = 1.0f;
	// Incrementar el tiempo transcurrido desde el último disparo
	TiempoDeDisparo += DeltaTime;

	// Verificar si ha pasado el tiempo suficiente para disparar
	if (TiempoDeDisparo >= Intervalo)
	{
		// Reiniciar el contador de tiempo
		TiempoDeDisparo = 0.0f;

		// Llamar a la función para disparar
		DispararNaveNodriza();
	}
}

void ANaveEnemigaNodriza::MovimientoNaveNodriza(float DeltaTime)
{
	float PosicionInicialX = -500.0f;
	FVector PosicionActual = GetActorLocation();

	float NuevaX = DeltaTime * velocidad;

	PosicionActual = FVector(PosicionActual.X + NuevaX, PosicionActual.Y, PosicionActual.Z);
	if (PosicionActual.X >= 0)
	{
		PosicionActual.X = PosicionInicialX;
	}
	SetActorLocation(PosicionActual);
}

void ANaveEnemigaNodriza::DispararNaveNodriza()
{
	FVector PosicionActualNaveEnemigaCaza = GetActorLocation();
	FRotator RotacionActualNaveEnemigaCaza = GetActorRotation();

	FVector DireccionDisparo = RotacionActualNaveEnemigaCaza.Vector();
	PosicionActualNaveEnemigaCaza += DireccionDisparo * 100;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AGalaga_USFX_L02Projectile>(PosicionActualNaveEnemigaCaza, RotacionActualNaveEnemigaCaza);
	}
}

