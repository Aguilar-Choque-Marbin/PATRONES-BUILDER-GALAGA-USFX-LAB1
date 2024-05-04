// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNavesAereas.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"

ANaveEnemiga* AFabricaNavesAereas::CreacionNaves(int tipo)
{
	if (tipo == 1)
	{
		return GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass());
	}
	if (tipo == 2)
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass());
	}
	return nullptr;
}
