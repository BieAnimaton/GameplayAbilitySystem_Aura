// Copyright Nevasca


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; // se tem um boolean B replicado - essencialmente no multiplayer, é quando uma entidade muda no server -
						// ao mudar, o servidor vai replicar para todos os clientes - responder ao dado alterado e entregar aos clientes

}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit; // varíavel hit
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit); // hit result
	if (!CursorHit.bBlockingHit) return; // se n tiver hit, retorna nada

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor()); // pegar o ator que levou o hit

	/*
	Line trace from cursor. There are several scenarios:
	 A. LastActor is null && ThisActor is null
	     - Do nothing
	 B. LastActor is null && ThisActor is valid
	     - Highlight ThisActor
	 C. LastActor is valid && ThisActor is null
	     - UnHighlight LastActor
	 D. Both actors are valid, but LastActor != ThisActor
	     - UnHighlight LastActor, and Highlight ThisActor
	 E. Both actors are valid, and are the same actor
	     - Do nothing
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A - both are null, do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else //both actors are valid
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
	
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay(); // chamando a implementação do método BeginPlay da classe pai ou base
	                    // garante que o comportamento padrão definido na classe pai ainda seja executado
	check(AuraContext); // verificar o contexto de Aura para ver se roda o jogo sem crashar

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		               // subsystems are singletons
	if (Subsystem) {
		Subsystem->AddMappingContext(AuraContext, 0); // simples input map context com prioridade 0
	}
	
	bShowMouseCursor = true; // ver o cursor
	DefaultMouseCursor = EMouseCursor::Default; // tipo do cursor

	FInputModeGameAndUI InputModeData; // input do teclado e mouse que podem afetar widgets UI
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // não travar o mouse na viewport
	InputModeData.SetHideCursorDuringCapture(false); // enquanto cursor é caputrado, ele não desaparece
	SetInputMode(InputModeData); // para usar os inputmodes definidos acima
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	                                      // jogo crasha se o cast falhar

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	                         // vai juntar tudo e fazer o movimento ser reconhecido
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>(); // cria um input action na forma de vector2d -
	                                                                   // pode acessar x e y
	const FRotator Rotation = GetControlRotation(); // inicia com a rotação atual
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f); // iniciar com 0 de pitch, yaw e 0 para roll

	const FVector FowardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // devolve o vetor andar p frente com rotação
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // o mesmo q o de cima, para o eixo y

	if (APawn* ControlledPawn = GetPawn<APawn>()) // se controller pawn (obter pawn) for null, n faz nada
	{
		ControlledPawn->AddMovementInput(FowardDirection, InputAxisVector.Y); // move para frente ou trás
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X); // move para direita ou esquerda
	}
}
