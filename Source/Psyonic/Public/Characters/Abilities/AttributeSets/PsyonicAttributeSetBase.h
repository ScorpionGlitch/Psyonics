// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PsyonicAttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PSYONIC_API UPsyonicAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Character Level", ReplicatedUsing=OnRep_CharacterLevel)
	FGameplayAttributeData CharacterLevel;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, CharacterLevel)
	
	UPROPERTY(BlueprintReadOnly, Category="Health", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, Health)

	UPROPERTY(BlueprintReadOnly, Category="Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category="Psyonic", ReplicatedUsing=OnRep_Psyonic)
	FGameplayAttributeData Psyonic;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, Psyonic)

	UPROPERTY(BlueprintReadOnly, Category="Psyonic", ReplicatedUsing=OnRep_MaxPsyonic)
	FGameplayAttributeData MaxPsyonic;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, MaxPsyonic)

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UPsyonicAttributeSetBase, Damage)

	UFUNCTION()
	virtual void OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel);
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	virtual void OnRep_Psyonic(const FGameplayAttributeData& OldPsyonic);
	UFUNCTION()
	virtual void OnRep_MaxPsyonic(const FGameplayAttributeData& OldMaxPsyonic);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
