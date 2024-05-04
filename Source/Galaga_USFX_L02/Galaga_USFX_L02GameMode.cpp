// Copyright Epic Games, Inc. All Rights Reserved.


#include "Galaga_USFX_L02GameMode.h"
#include "Galaga_USFX_L02Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "FabricaNavesAereas.h"
#include "FabricaNavesTerrestres.h"
#include "DirectorNaveNodriza.h" //añadimos las librerias necesarias para el builder
#include "Builder_1.h" //añadimos las librerias necesarias
#include "NaveEnemigaNodriza.h" //añadimos las librerias necesarias

AGalaga_USFX_L02GameMode::AGalaga_USFX_L02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L02Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L02GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
	AFabricaNaves* NaveCaza = GetWorld()->SpawnActor<AFabricaNavesAereas>(AFabricaNavesAereas::StaticClass());
	AFabricaNaves* NaveTransporte = GetWorld()->SpawnActor<AFabricaNavesTerrestres>(AFabricaNavesTerrestres::StaticClass());


	FVector PosicionNaveCaza = FVector(0.0f, 0.0f, 250.0f);
	FVector PosicionNaveTransporte = FVector(0.0f, 600.0f, 250.0f);

	Builder5 = GetWorld()->SpawnActor<ABuilder_1>(ABuilder_1::StaticClass());
	DirectorNaveNodriza = GetWorld()->SpawnActor<ADirectorNaveNodriza>(ADirectorNaveNodriza::StaticClass());
	DirectorNaveNodriza->OrdenBuilder(Builder5);
	ANaveEnemigaNodriza* NaveNodriza1 = DirectorNaveNodriza->NaveNodriza();

	for (int i = 0; i < 3; i++)
	{
		FVector PosicionActualNaveCaza = FVector(PosicionNaveCaza.X, PosicionNaveCaza.Y + i * 200, PosicionNaveCaza.Z);
		ANaveEnemiga* NaveEnemiga1 = NaveCaza->CreacionNaves(1);
		NaveEnemiga1->SetActorLocation(PosicionActualNaveCaza);
		//NaveEnemiga1->Mover();
	}

	for (int i = 0; i < 3; i++)
	{
		FVector PosicionActualNaveTransporte = FVector(PosicionNaveTransporte.X, PosicionNaveTransporte.Y + i * 200, PosicionNaveTransporte.Z);
		ANaveEnemiga* NaveEnemiga2 = NaveTransporte->CreacionNaves(2);
		NaveEnemiga2->SetActorLocation(PosicionActualNaveTransporte);
	}
}

void AGalaga_USFX_L02GameMode::MostrarPosicionesNavesEnemigas()
{
	for (auto ElementoActual : TMPosicionesNavesEnemigas) {
		ANaveEnemiga* naveEnemigaActual = ElementoActual.Key;
		FVector posicionActualNaveEnemiga = ElementoActual.Value;
		FString mensaje = "La nave " + naveEnemigaActual->GetNombre() + " esta en la posicion> " + posicionActualNaveEnemiga.ToString();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, mensaje);

			/*FString mensaje = "Nombre NaveEnemiga: " + Clave->GetNombre() + " Posicion NaveEnemiga: " + Valor.ToString();
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mensaje);*/

		}

		TMPosicionesNavesEnemigas[naveEnemigaActual] = naveEnemigaActual->GetActorLocation();
	}
}