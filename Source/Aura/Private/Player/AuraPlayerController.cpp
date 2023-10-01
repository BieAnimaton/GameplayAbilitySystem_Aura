// Copyright Nevasca


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; // se tem um boolean B replicado - essencialmente no multiplayer, � quando uma entidade muda no server -
						// ao mudar, o servidor vai replicar para todos os clientes - responder ao dado alterado e entregar aos clientes

}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay(); // chamando a implementa��o do m�todo BeginPlay da classe pai ou base
	                    // garante que o comportamento padr�o definido na classe pai ainda seja executado
	check(AuraContext); // verificar o contexto de Aura para ver se roda o jogo sem crashar

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		               // subsystems are singletons
	check(Subsystem); // checa se existe ou n�o - se subsystem for null, vai crashar aqui
	Subsystem->AddMappingContext(AuraContext, 0); // simples input map context com prioridade 0
	
	bShowMouseCursor = true; // ver o cursor
	DefaultMouseCursor = EMouseCursor::Default; // tipo do cursor

	FInputModeGameAndUI InputModeData; // input do teclado e mouse que podem afetar widgets UI
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // n�o travar o mouse na viewport
	InputModeData.SetHideCursorDuringCapture(false); // enquanto cursor � caputrado, ele n�o desaparece
	SetInputMode(InputModeData); // para usar os inputmodes definidos acima
}
