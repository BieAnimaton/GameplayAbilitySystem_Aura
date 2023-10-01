// Copyright Nevasca

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController(); // construtor

protected:
	virtual void BeginPlay() override; // sobrescrever BeginPlay
	virtual void SetupInputComponent() override; // sobrescrever SetupInputComponent
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext; // ponteiro para o input map context

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction; // ponteiro para o movimento

	void Move(const FInputActionValue& InputActionValue); // função para mover
};
