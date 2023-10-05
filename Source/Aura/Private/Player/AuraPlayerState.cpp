// Copyright Nevasca


#include "Player/AuraPlayerState.h"
#include <AbilitySystem/AuraAttributeSet.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent"); // construção do ability system component
	AbilitySystemComponent->SetIsReplicated(true); // confirma a replicação
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); // replicação mista - para multiplayer e playert jogável

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f; // a frequência em que o server vai tentar atualizar os clientes
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
