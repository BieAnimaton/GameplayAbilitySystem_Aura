// Copyright Nevasca


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon"); // criar um subobjeto pardrão skeletal mesh para arma
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket")); // junta a arma no socket WeaponHandSocket
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision); // remove a colição da arma

}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

