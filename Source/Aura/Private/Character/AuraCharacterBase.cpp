// Copyright Nevasca


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon"); // criar um subobjeto pardr�o skeletal mesh para arma
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket")); // junta a arma no socket WeaponHandSocket
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision); // remove a coli��o da arma

}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

