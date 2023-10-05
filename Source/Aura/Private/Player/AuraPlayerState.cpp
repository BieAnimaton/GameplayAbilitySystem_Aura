// Copyright Nevasca


#include "Player/AuraPlayerState.h"
#include <AbilitySystem/AuraAttributeSet.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent"); // constru��o do ability system component
	AbilitySystemComponent->SetIsReplicated(true); // confirma a replica��o
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); // replica��o mista - para multiplayer e playert jog�vel

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f; // a frequ�ncia em que o server vai tentar atualizar os clientes
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
