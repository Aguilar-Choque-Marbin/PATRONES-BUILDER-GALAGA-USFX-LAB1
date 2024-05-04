// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNavesTerrestres.h"
#include "NaveEnemigaTransporte.h"

ANaveEnemiga* AFabricaNavesTerrestres::CreacionNaves(int tipo)
{
	if (tipo == 2)
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass());
	}
	return nullptr;
}
