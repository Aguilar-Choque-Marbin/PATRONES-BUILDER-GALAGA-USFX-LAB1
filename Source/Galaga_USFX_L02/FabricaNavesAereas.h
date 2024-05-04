// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaNaves.h"
#include "FabricaNavesAereas.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L02_API AFabricaNavesAereas : public AFabricaNaves
{
	GENERATED_BODY()
public:
	virtual ANaveEnemiga* CreacionNaves(int tipo) override;
};
