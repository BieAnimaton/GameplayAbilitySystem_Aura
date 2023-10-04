// Copyright Nevasca

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; // ponteiro retornado pelo iability.
	UAttributeSet* GetAttributeSet() const { return AttributeSet; } // ponteiro retornado ''

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; // ponteiro para ability system

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
