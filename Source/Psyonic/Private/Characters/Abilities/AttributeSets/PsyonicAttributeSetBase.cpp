// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/AttributeSets/PsyonicAttributeSetBase.h"

#include "Net/UnrealNetwork.h"

void UPsyonicAttributeSetBase::OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPsyonicAttributeSetBase, CharacterLevel, OldCharacterLevel)
}

void UPsyonicAttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPsyonicAttributeSetBase, Health, OldHealth)
}

void UPsyonicAttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPsyonicAttributeSetBase, MaxHealth, OldMaxHealth)
}

void UPsyonicAttributeSetBase::OnRep_Psyonic(const FGameplayAttributeData& OldPsyonic)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPsyonicAttributeSetBase, Psyonic, OldPsyonic)
}

void UPsyonicAttributeSetBase::OnRep_MaxPsyonic(const FGameplayAttributeData& OldMaxPsyonic)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPsyonicAttributeSetBase, MaxPsyonic, OldMaxPsyonic)
}

void UPsyonicAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPsyonicAttributeSetBase, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPsyonicAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPsyonicAttributeSetBase, Psyonic, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPsyonicAttributeSetBase, MaxPsyonic, COND_None, REPNOTIFY_Always)
}
