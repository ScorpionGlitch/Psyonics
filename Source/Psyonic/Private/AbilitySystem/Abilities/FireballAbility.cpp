#include "AbilitySystem/Abilities/FireballAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Effects/FireballEffect.h"

UFireballAbility::UFireballAbility()
{
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Fireball")));
}

void UFireballAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

bool UFireballAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
	const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

FGameplayEffectSpecHandle UFireballAbility::ApplyFireballEffect()
{
	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(UFireballEffect::StaticClass(), GetAbilityLevel(), EffectContextHandle);
	if (EffectSpecHandle.IsValid())
	{
		// Modify the effect spec as needed
		// For example, you can add custom modifiers or set other properties of the effect

		return EffectSpecHandle;
	}

	return FGameplayEffectSpecHandle();
}
