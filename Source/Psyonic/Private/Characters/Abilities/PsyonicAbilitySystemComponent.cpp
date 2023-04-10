// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/PsyonicAbilitySystemComponent.h"

void UPsyonicAbilitySystemComponent::ReceiveDamage(UPsyonicAbilitySystemComponent* SourceASC, float UnmitigatedDamage,
	float MitigatedDamage)
{
	ReceivedDamage.Broadcast(SourceASC, UnmitigatedDamage,MitigatedDamage);
}
