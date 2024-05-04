// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BuilderPrincipal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorNaveNodriza.generated.h"

UCLASS()
class GALAGA_USFX_L02_API ADirectorNaveNodriza : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorNaveNodriza();
	void OrdenBuilder(AActor* Builder); // Funci�n que recibe un actor y lo ordena a construir
	void MovimientoNaveNodriza(); // Funci�n que mueve la nave nodriza
	void DispararNaveNodriza(); // Funci�n que dispara la nave nodriza

	class ANaveEnemigaNodriza* NaveNodriza(); // Variable que almacena la nave nodriza
	IBuilderPrincipal* Builder1; // Variable que almacena el builder

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
