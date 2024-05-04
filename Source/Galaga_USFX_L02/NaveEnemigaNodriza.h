// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L02_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemigaNodriza();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MovimientoNaveNodriza(float DeltaTime); // Función que mueve la nave nodriza
	void DispararNaveNodriza(); // Función que dispara la nave nodriza
};
