// Copyright Nevasca

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat"); // diz como o ponteiro deve ser
	TObjectPtr<USkeletalMeshComponent> Weapon; // pointer, representa a arma de cada skeletal mesh
};
