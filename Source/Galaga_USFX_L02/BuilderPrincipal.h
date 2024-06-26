// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderPrincipal.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderPrincipal : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L02_API IBuilderPrincipal
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual class ANaveEnemigaNodriza* NaveNodriza() = 0; // Variable que almacena la nave nodriza
	virtual void MovimientoNaveNodriza() = 0; // Funci�n que mueve la nave nodriza
	virtual void DispararNaveNodriza() = 0; // Funci�n que dispara la nave nodriza
};
