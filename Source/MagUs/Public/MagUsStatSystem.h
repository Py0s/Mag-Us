// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "MagUsStatSystem.generated.h"

class AMagUsCharacter;

/**
 * Classe impl�mentant toutes les formules de gameplay
 */
UCLASS()
class MAGUS_API UMagUsStatSystem : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
		float CalcDamage(AMagUsCharacter * attacker, AMagUsCharacter * target);

};
