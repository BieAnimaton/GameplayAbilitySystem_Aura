// Copyright Nevasca


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; // ativar rotação
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f); // velocidade na direção yaw
	GetCharacterMovement()->bConstrainToPlane = true; // restringir o movimento ao plano
	GetCharacterMovement()->bSnapToPlaneAtStart = true; // garantir o encaixe com o plano

	bUseControllerRotationPitch = false; // o personagem n vai usar a rotação pitch do controlador
	bUseControllerRotationRoll = false;  // '' roll
	bUseControllerRotationYaw = false;   // '' yaw
}
