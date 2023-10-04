// Copyright Nevasca

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface // iability... implementado no auracharacter....
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; // ponteiro retornado pelo iability.
	UAttributeSet* GetAttributeSet() const { return AttributeSet; } // ponteiro retornado ''

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat"); // diz como o ponteiro deve ser
	TObjectPtr<USkeletalMeshComponent> Weapon; // pointer, representa a arma de cada skeletal mesh

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; // ponteiro para ability system

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
