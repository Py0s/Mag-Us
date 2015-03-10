// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "MagUsSpell.h"
#include "MagUsBuffOff.h"
#include "MagUsProjectile.generated.h"

UCLASS(config=Game)
class AMagUsProjectile : public AMagUsSpell
{
	GENERATED_BODY()

protected:
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "false"))
	class UProjectileMovementComponent* ProjectileMovement;

	/** Damages of the Projectile */
	UPROPERTY(VisibleAnywhere, Category = Gameplay)
	float Damage;

	/** Debuf that will be applied to the hit Character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpellManagment)
	TSubclassOf<AMagUsBuffOff> DebufClass;

public:
	AMagUsProjectile(const FObjectInitializer& ObjectInitializer);
	AMagUsProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void SetDamage(float damageAmount);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

