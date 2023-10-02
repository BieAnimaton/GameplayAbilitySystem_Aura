// Copyright Nevasca


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"
#include "PrimitiveComponentId.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block); // altera a collisão para custom e visiblity block
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
	GetMesh()->SetRenderCustomDepth(false); // não mostrando a borda do mesh
	Weapon->SetRenderCustomDepth(false);
}
