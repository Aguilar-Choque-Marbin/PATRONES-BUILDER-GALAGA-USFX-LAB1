// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BuilderPrincipal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builder_1.generated.h"

UCLASS()
class GALAGA_USFX_L02_API ABuilder_1 : public AActor , public IBuilderPrincipal
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder_1();
	class ANaveEnemigaNodriza* NaveNodrizas; // Variable que almacena la nave nodriza

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual class ANaveEnemigaNodriza* NaveNodriza() override; // Variable que almacena la nave nodriza
	virtual void MovimientoNaveNodriza() override; // Función que mueve la nave nodriza
	virtual void DispararNaveNodriza() override; // Función que dispara la nave nodriza
};
