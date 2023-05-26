#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FireballAbility.generated.h"

UCLASS()
class PSYONIC_API UFireballAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UFireballAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
		const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const override;

private:
	FGameplayEffectSpecHandle ApplyFireballEffect();
};