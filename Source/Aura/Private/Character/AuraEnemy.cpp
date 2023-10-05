// Copyright Nevasca


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"
#include <AbilitySystem/AuraAbilitySystemComponent.h>
#include <AbilitySystem/AuraAttributeSet.h>

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block); // altera a collis�o para custom e visiblity block

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent"); // constru��o do ability system component
	AbilitySystemComponent->SetIsReplicated(true); // confirma a replica��o
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal); // replica��o m�nima - para multiplayer e IA

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true); // mostrando a borda do mesh
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED); // definir o tamanho (250)
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false); // n�o mostrando a borda do mesh
	Weapon->SetRenderCustomDepth(false);
}
