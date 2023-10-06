// Copyright Nevasca


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"

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

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();	
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this); // owner auraplayerstate e avatar this
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
