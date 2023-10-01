// Copyright Nevasca


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; // se tem um boolean B replicado - essencialmente no multiplayer, é quando uma entidade muda no server -
						// ao mudar, o servidor vai replicar para todos os clientes - responder ao dado alterado e entregar aos clientes

}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay(); // chamando a implementação do método BeginPlay da classe pai ou base
	                    // garante que o comportamento padrão definido na classe pai ainda seja executado
	check(AuraContext); // verificar o contexto de Aura para ver se roda o jogo sem crashar

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		               // subsystems are singletons
	check(Subsystem); // checa se existe ou não - se subsystem for null, vai crashar aqui
	Subsystem->AddMappingContext(AuraContext, 0); // simples input map context com prioridade 0
	
	bShowMouseCursor = true; // ver o cursor
	DefaultMouseCursor = EMouseCursor::Default; // tipo do cursor

	FInputModeGameAndUI InputModeData; // input do teclado e mouse que podem afetar widgets UI
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // não travar o mouse na viewport
	InputModeData.SetHideCursorDuringCapture(false); // enquanto cursor é caputrado, ele não desaparece
	SetInputMode(InputModeData); // para usar os inputmodes definidos acima
}
